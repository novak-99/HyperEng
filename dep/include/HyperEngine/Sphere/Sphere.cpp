#include "Sphere.hpp"
#include "Constants/Constants.hpp"

#include <iostream>
#include <cmath>
#include <glad/glad.h>

namespace HyperEngine{
    Sphere::Sphere(float mass, float radius) : Particle(mass){ 
        this->mass = mass; 
        this->radius = radius; 

        initializeVectors();
    }

    Sphere::Sphere(Vec3 position, Vec3 velocity, Vec3 acceleration, float mass, float radius) : Particle(position, velocity,  acceleration, mass){
        this->position = position;
        this->velocity = velocity;
        this->acceleration = acceleration;

        this->mass = mass;
        this->radius = radius;

        initializeVectors();
    }

    float Sphere::getRadius(){ return radius; }

    void Sphere::setRadius(float radius){ this->radius = radius; }

    float Sphere::volume(){
        return 4/3 * M_PI * std::pow(radius, 3);
    }

    std::vector<float> Sphere::getVertices() { return vertices; }

    std::vector<int> Sphere::getIndices(){ return indices; }

    std::vector<float> Sphere::createVertices(){

        std::vector<float> vertices;

        // 21 * 21 points, 20 * 20 sectorss
        for(int i = 0; i <= NUMRINGS; i++){
            float phi = (M_PI / 2) - M_PI * (float(i) / float(NUMRINGS)); 
            for (int j = 0; j <= NUMSECTORS; j++){
                float theta = 2 * M_PI * (float(j) / float(NUMSECTORS));

                float x = radius * std::cosf(phi) * std::cosf(theta);
                float y = radius * std::cosf(phi) * std::sinf(theta);
                float z = radius * std::sinf(phi);

                vertices.push_back(x);
                vertices.push_back(y);
                vertices.push_back(z);

                vertices.push_back(255.0f);
                vertices.push_back(255.0f);
                vertices.push_back(255.0f);

                vertices.push_back(0.0f);
                vertices.push_back(0.0f);

            }
        }   
        return vertices;
    }

    std::vector<int> Sphere::createIndices(){
        std::vector<int> indices;
        // 21 * 21 points, 20 * 20 sectorss
        // float NUMRINGS= 20;
        // float NUMSECTORS = 20; 
        for(int i = 0; i < NUMRINGS; i++){
            for (int j = 0; j < NUMSECTORS; j++){
                int r1s1 = i * (NUMRINGS + 1) + j;
                int r2s1 = (i+1) * (NUMRINGS + 1) + j;

                int r1s2 = i * (NUMRINGS + 1) + (j + 1);
                int r2s2 = (i+1) * (NUMRINGS + 1) + (j + 1);

                // change to arrays
                indices.push_back(r1s1);
                indices.push_back(r2s1);
                indices.push_back(r1s2);

                indices.push_back(r1s2);
                indices.push_back(r2s1);
                indices.push_back(r2s2);
            }
        }
        return indices;
    }

    void Sphere::initializeVectors(){
        vertices = createVertices();
        indices = createIndices();
    }

    void Sphere::handleVAP(){
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTICESSIZE * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, VERTICESSIZE * sizeof(float), (void*)(COORDSSIZE * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, VERTICESSIZE * sizeof(float), (void*)((COORDSSIZE + COLORSSIZE) * sizeof(float)));
        glEnableVertexAttribArray(2);
    }

}