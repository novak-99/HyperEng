#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include "ShaderSource.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <cmath>
#include "Particle/Particle.hpp"
#include "Vec3/Vec3.hpp"
#include "Constants/Constants.hpp"
#include "Force/SpringForce.hpp"
#include "Force/BuoyancyForce.hpp"
#include "Sphere/Sphere.hpp"
#include "World/World.hpp"

using namespace HyperEngine;


// https://stackoverflow.com/questions/43985162/opengl-or-glfw-renders-ok-only-when-moving-the-window
// Fixs rendering on mac w/out monitor. 
void fix_render_on_mac(GLFWwindow* window) {
#ifdef __APPLE__
    static bool macMoved = false;
    if(!macMoved) {
        int x, y;
        glfwGetWindowPos(window, &x, &y);
        glfwSetWindowPos(window, ++x, y);
        macMoved = true;
    }
#endif
}

int main(){

    World world; 

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    GLFWwindow* win = glfwCreateWindow(800, 800, "HyperEngine", NULL, NULL);

    if(win == NULL){
        std::cerr << "Problem with window" << "\n";
        glfwTerminate();
        return -1; 
    }

    glfwMakeContextCurrent(win);

    gladLoadGL();

    glViewport(0, 0, 800, 800);

    // Square

    // float vertices[] =
    // { //     COORDINATES     /        COLORS          /   TexCoord  //
    //     -0.5f, 0.5f, -0.5f,     0.0f, 0.0f, 0.0f,	     0.0, 0.0f,
    //     -0.5f, 0.5f, 0.5f,      0.0f, 0.0f, 0.0f,	     0.0f, 1.0f,
    //     0.5f, 0.5f,  -0.5f,     0.0f, 0.0f, 0.0f,	     1.0f, 0.0f,
    //     0.5f, 0.5,  0.5f,       0.0f, 0.0f, 0.0f,	     1.0f, 1.0f,

    //     -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,	     0.0f, 0.0f,
    //     -0.5f, -0.5f, 0.5f,     0.0f, 0.0f, 0.0f,	     0.0f, 0.1f,
    //     0.5f, -0.5f,  -0.5f,    0.0f, 0.0f, 0.0f,	     1.0f, 0.0f,
    //     0.5f, -0.5,  0.5f,      0.0f, 0.0f, 0.0f,	     1.0f, 1.0f,
    // };

    // // Indices for vertices order
    // int indices[] =
    // {
    //     0, 1, 2, 
    //     1, 2, 3,

    //     4, 5, 6,
    //     5, 6, 7,

    //     6, 2, 7,
    //     2, 7, 3,

    //     0, 4, 1,
    //     4, 5, 1,

    //     0, 4, 2, 
    //     2, 0, 6,

    //     1, 5, 3, 
    //     3, 5, 7,
    // };

    // Algorithm from: http://www.songho.ca/opengl/gl_sphere.html

    float numRings = 20; 
    float numSectors = 20; 
    float radius = 3.0f; 

    std::vector<float> vertices_vec;

    // 21 * 21 points, 20 * 20 sectorss
    for(int i = 0; i <= numRings; i++){
        float phi = (M_PI / 2) - M_PI * (float(i) / float(numRings)); 
        for (int j = 0; j <= numSectors; j++){
            float theta = 2 * M_PI * (float(j) / float(numSectors));

            float x = radius * std::cosf(phi) * std::cosf(theta);
            float y = radius * std::cosf(phi) * std::sinf(theta);
            float z = radius * std::sinf(phi);

            vertices_vec.push_back(x);
            vertices_vec.push_back(y);
            vertices_vec.push_back(z);

            vertices_vec.push_back(255.0f);
            vertices_vec.push_back(255.0f);
            vertices_vec.push_back(255.0f);

            vertices_vec.push_back(0.0f);
            vertices_vec.push_back(0.0f);

        }
    }   



    std::vector<int> indices_vec;
    // 21 * 21 points, 20 * 20 sectorss
    // float numRings= 20;
    // float numSectors = 20; 
    for(int i = 0; i < numRings; i++){
        for (int j = 0; j < numSectors; j++){
            int r1s1 = i * (numRings + 1) + j;
            int r2s1 = (i+1) * (numRings + 1) + j;

            int r1s2 = i * (numRings + 1) + (j + 1);
            int r2s2 = (i+1) * (numRings + 1) + (j + 1);

            // change to arrays
            indices_vec.push_back(r1s1);
            indices_vec.push_back(r2s1);
            indices_vec.push_back(r1s2);

            indices_vec.push_back(r1s2);
            indices_vec.push_back(r2s1);
            indices_vec.push_back(r2s2);
        }
    }


    float vertices[vertices_vec.size()];
    std::copy(vertices_vec.begin(), vertices_vec.end(), vertices);

    int indices[indices_vec.size()];
    std::copy(indices_vec.begin(), indices_vec.end(), indices);

    ShaderSource reader;

    std::string vertCode = reader.readShaderSource("Shaders/default.vert");
    std::string fragCode = reader.readShaderSource("Shaders/default.frag");

    const char* vertexShaderSource = vertCode.c_str();
    const char* fragmentShaderSource = fragCode.c_str();

    uint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    uint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    uint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    uint VAO, VBO, EBO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    uint scaleID = glGetUniformLocation(shaderProgram, "scale");




    glEnable(GL_DEPTH_TEST);

    glfwSwapBuffers(win);

    // switch to sphere..
    Sphere particle(Vec3(0.0, 10.0, -10.0), Vec3(0, -5, 0), Vec3(0,0.0,0), 5, radius);
    Sphere particle2(Vec3(0.0, -10.0, -10.0), Vec3(0, 5, 0), Vec3(0,0.0,0), 5, radius);

    world.addObj(&particle);
    world.addObj(&particle2);

    float prevTime = glfwGetTime();

    while(!glfwWindowShouldClose(win)){
        glClearColor(0.17f, 0.07f, 0.14f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram);

        float currTime = glfwGetTime();
        float t = currTime - prevTime; 
        prevTime = currTime;
        {
            world.checkSphereCollison();
            
            world.getObjects()[0]->integrate(t);


            glm::mat4 model = glm::mat4(1.0f);
            glm::mat4 view = glm::mat4(1.0f);
            glm::mat4 proj = glm::mat4(1.0f);

            model = glm::translate(model, glm::vec3(world.getObjects()[0]->getPosition().getIComponent(), world.getObjects()[0]->getPosition().getJComponent(), world.getObjects()[0]->getPosition().getKComponent()));
            model = glm::rotate(model, glm::radians(35.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
            proj = glm::perspective(glm::radians(45.0f), float(800/800), 0.1f, 100.0f);

            std::cout << "OLD VEL" << "\n";
            world.getObjects()[0]->getVelocity().print();
            world.getObjects()[0]->getPosition().print();

            int modelID = glGetUniformLocation(shaderProgram, "model");
            glUniformMatrix4fv(modelID, 1, GL_FALSE, glm::value_ptr(model));
            int viewID = glGetUniformLocation(shaderProgram, "view");
            glUniformMatrix4fv(viewID, 1, GL_FALSE, glm::value_ptr(view));
            int projID = glGetUniformLocation(shaderProgram, "proj");
            glUniformMatrix4fv(projID, 1, GL_FALSE, glm::value_ptr(proj));





            glUniform1f(scaleID, 1.5);

            //glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
        }

        {

            world.checkSphereCollison();
            
            world.getObjects()[1]->integrate(t);


            glm::mat4 model = glm::mat4(1.0f);
            glm::mat4 view = glm::mat4(1.0f);
            glm::mat4 proj = glm::mat4(1.0f);

            model = glm::translate(model, glm::vec3(world.getObjects()[1]->getPosition().getIComponent(), world.getObjects()[1]->getPosition().getJComponent(), world.getObjects()[1]->getPosition().getKComponent()));
            model = glm::rotate(model, glm::radians(35.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
            proj = glm::perspective(glm::radians(45.0f), float(800/800), 0.1f, 100.0f);

            std::cout << t << "\n";

            std::cout << "OLD VEL" << "\n";
            world.getObjects()[1]->getVelocity().print();
            world.getObjects()[1]->getPosition().print();

            int modelID = glGetUniformLocation(shaderProgram, "model");
            glUniformMatrix4fv(modelID, 1, GL_FALSE, glm::value_ptr(model));
            int viewID = glGetUniformLocation(shaderProgram, "view");
            glUniformMatrix4fv(viewID, 1, GL_FALSE, glm::value_ptr(view));
            int projID = glGetUniformLocation(shaderProgram, "proj");
            glUniformMatrix4fv(projID, 1, GL_FALSE, glm::value_ptr(proj));





            glUniform1f(scaleID, 1.5);

            //glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
        }
        glfwSwapBuffers(win);
        fix_render_on_mac(win);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    //glDeleteTextures(1, &texture);





    glfwTerminate();

    return 0;
}