#ifndef WORLD_HPP
#define WORLD_HPP

#include "Vector3/Vector3.hpp"
#include <vector>

namespace HyperEngine{

    class World{
        public: 
            void addObject(Object* object);
            void Step(float t);

        private:
            std::vector<Object*> sceneObjects; 

    };

}

#endif // WORLD_HPP