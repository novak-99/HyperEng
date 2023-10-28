#ifndef VAO_HPP
#define VAO_HPP

#include <glad/glad.h>

class VAO{
    public:  
        ~VAO();

        void bind();
        void unbind();
        void initializeVAO();

    private:
        unsigned int ID; 
};


#endif // VAO_HPP