#include "EBO.hpp"

EBO::EBO(std::vector<int>& indices){

    this->indices = new int[indices.size()];
    std::copy(indices.begin(), indices.end(), this->indices);
}

EBO::~EBO(){
    glDeleteBuffers(1, &ID);
    delete indices;
}

void EBO::bind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::unbind(){
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::initializeEBO(){



    glGenBuffers(1, &ID);
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}