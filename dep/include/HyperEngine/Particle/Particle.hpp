#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "Vec3/Vec3.hpp"

namespace HyperEngine{

    class Particle{
        public:
            Particle(float mass);
            Particle(Vec3 position, Vec3 velocity, Vec3 acceleration, float mass);

            Vec3 getPosition();
            void setPosition(Vec3 position);

            Vec3 getVelocity();
            void setVelocity(Vec3 velocity);

            Vec3 getAcceleration();
            void setAcceleration(Vec3 acceleration);

            float getMass();
            void setMass(float mass);

            void addForce(Vec3 force);

            void integrate(float t);


        private:
            Vec3 position;
            Vec3 velocity; 
            Vec3 acceleration;

            Vec3 aggregateForce; 

            //float damping; 
            float mass; 
    };
}

#endif // PARTICLE_HPP