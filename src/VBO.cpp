#include "VBO.hpp"

VBO::VBO(std::vector<float>& vertices){

    this->vertices = new float[vertices.size()];
    std::copy(vertices.begin(), vertices.end(), this->vertices);
}

VBO::~VBO(){
    glDeleteBuffers(1, &ID);
    delete vertices;
}

void VBO::bind(){
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::unbind(){
   glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::initializeVBO(){
    glGenBuffers(1, &ID);
    bind();
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}