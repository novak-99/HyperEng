#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "Vector3/Vector3.hpp"

namespace HyperEngine{

    class Particle{
        public:
            Particle();
            Particle(float mass);
            Particle(Vector3 position, Vector3 velocity, Vector3 acceleration, float mass, float damping);

            void integrate(float duration);

            // Vector3 getForce();
            // void setForce(Vector3 force);

            Vector3 getPosition();
            void setPosition(Vector3 position);

            Vector3 getVelocity();
            void setVelocity(Vector3 velocity);

            Vector3 getAcceleration();
            void setAcceleration(Vector3 force);

            float getInverseMass();
            void setInverseMass(float mass);

            float getMass();
            void setMass(float mass);

        private:
            // Vector3 force; 
            Vector3 position; 
            Vector3 velocity; 
            Vector3 acceleration; 
            
            float damping; 
            float inverseMass; 
    };
}

#endif // PARTICLE_HPP