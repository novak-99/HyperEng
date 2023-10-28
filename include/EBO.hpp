#ifndef EBO_HPP
#define EBO_HPP

#include <glad/glad.h>
#include <vector>

class EBO{
    public:  
        EBO(std::vector<int>& indices);
        ~EBO();

        void bind();
        void unbind();
        void initializeEBO();

    private:
        unsigned int ID; 
        int* indices; 
};


#endif // EBO_HPP