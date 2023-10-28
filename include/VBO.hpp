#ifndef VBO_HPP
#define VBO_HPP

#include <glad/glad.h>
#include <vector>

class VBO{
    public:  
        VBO(std::vector<float>& vertices);
        ~VBO();

        void bind();
        void unbind();
        void initializeVBO();

    private:
        unsigned int ID; 
        float* vertices; 
};


#endif // VBO_HPP