#include <fstream>
#include <iostream>
#include "ShaderProgram.hpp"

shaderProgram::shaderProgram(){
    createVertexShader(); // implicitly inits vertex shader ID 
    createFragmentShader(); // implicitly inits frag shader ID 
    createShaderProgram(); // implicitly inits program shader ID
}

shaderProgram::~shaderProgram(){
    deleteProgram();
}

void ShaderProgram::createVertexShader(){
    std::string vertCode = readShaderSource("Shaders/default.vert");
    const char* vertexShaderSource = vertCode.c_str();

    vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShaderID);
}

void ShaderProgram::createFragmentShader(){
    std::string fragCode = readShaderSource("Shaders/default.frag");
    const char* fragmentShaderSource = fragCode.c_str();

    fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShaderID);
}

void ShaderProgram::createProgram(){
    shaderProgramID = glCreateProgram();
    glAttachShader(shaderProgramID, vertexShaderID);
    glAttachShader(shaderProgramID, fragmentShaderID);
    glLinkProgram(shaderProgramID);

}

void ShaderProgram::useProgram(){
    glUseProgram(shaderProgram);
}

void ShaderProgram::deleteShaders(){
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

void ShaderProgram::deleteProgram(){
    glDeleteProgram(shaderProgramID);
}

std::string ShaderProgram::readShaderSource(std::string filename){
    std::string content; 
    std::ifstream fileStream(filename);

    if(!fileStream.is_open()){
        std::cerr << "Problem opening with file " << filename << "." "\n";
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()){
        std::getline(fileStream, line);
        content.append(line + '\n');
    }

    fileStream.close();

    return content; 
}