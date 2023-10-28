#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Particle/Particle.hpp"
#include <vector>
#include "Vec3/Vec3.hpp"

namespace HyperEngine{

    class Sphere : public Particle{
        public:
            Sphere(float radius, float mass);
            Sphere(Vec3 position, Vec3 velocity, Vec3 acceleration, float radius, float mass);

            float getRadius();

            void setRadius(float radius);

            float volume();

            std::vector<float> getVertices(); 
            std::vector<int> getIndices(); 

            void handleVAP();

        private:
            // TO DO:
            // change these to constats, maybe move them into a func for both initialization constructor funcs 
            const int NUMRINGS = 20;
            const int NUMSECTORS = 20;
            const int VERTICESSIZE = 8;
            const int COORDSSIZE = 3;
            const int COLORSSIZE = 3;
            

            std::vector<float> createVertices();
            std::vector<int> createIndices();

            void initializeVectors();

            std::vector<float> vertices; 
            std::vector<int> indices; 

            Vec3 position;
            Vec3 velocity; 
            Vec3 acceleration;

            Vec3 aggregateForce; 

            //float damping; 
            float mass; 

            // sphere specific
            float radius;
    };
}

#endif // SPHERE_HPP