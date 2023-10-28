#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Particle/Particle.hpp"
#include "Vec3/Vec3.hpp"

namespace HyperEngine{

    class Square : public Particle{
        public:
            Square(float sideLength, float mass);
            Square(Vec3 position, Vec3 velocity, Vec3 acceleration, float sideLength, float mass);

            float getSideLength();

            void setSideLength(float sideLength);

            float volume();

            std::vector<float> getVertices(); 
            std::vector<int> getIndices(); 


        private:
            std::vector<float> vertices; 
            std::vector<int> indices; 

            Vec3 position;
            Vec3 velocity; 
            Vec3 acceleration;

            Vec3 aggregateForce; 

            //float damping; 
            float mass; 

            // sphere specific
            float sideLength;
    };
}

#endif // SPHERE_HPP