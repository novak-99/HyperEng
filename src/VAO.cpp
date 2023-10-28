#include "VAO.hpp"

VAO::~VAO(){
    glDeleteVertexArrays(1, &ID);
}

void VAO::bind(){
    glBindVertexArray(ID);
}

void VAO::unbind(){
    glBindVertexArray(0);
}

void VAO::initializeVAO(){
    glGenVertexArrays(1, &ID);
    bind();
}