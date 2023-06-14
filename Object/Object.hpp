#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vector3/Vector3.hpp"

namespace HyperEngine{

    class Object{
        public:
            Object(float mass);
            Object(Vector3 force, Vector3 velocity, Vector3 position, float mass);
            Vector3 getForce();
            Vector3 getPosition();
            Vector3 getVelocity();
            float getMass();

        private:
            Vector3 force; 
            Vector3 velocity; 
            Vector3 position; 
            float mass; 
    };
}

#endif // OBJECT_HPP