#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include <glad/glad.h>
#include <string>

class shaderProgram{
    public:
        shaderProgram();
        ~shaderProgram();

        void createVertexShader();
        void createFragmentShader();
        void createProgram();
        void useProgram();

    private:
        std::string readShaderSource(std::string filename);
        void deleteShaders();
        void deleteProgram();
        uint vertexShaderID; 
        uint fragmentShaderID; 
        uint programID;
        


};

#endif // SHADERPROGRAM_HPP