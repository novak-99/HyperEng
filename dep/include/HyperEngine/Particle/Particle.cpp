#include "Particle.hpp"
#include "Constants/Constants.hpp"

#include <iostream>

namespace HyperEngine{
    Particle::Particle(float mass){ this->mass = mass; }

    Particle::Particle(Vec3 position, Vec3 velocity, Vec3 acceleration, float mass){
        this->position = position;
        this->velocity = velocity;
        this->acceleration = acceleration;

        this->mass = mass;
    }

    Vec3 Particle::getPosition(){ return position; }

    void Particle::setPosition(Vec3 position){ this->position = position; }

    Vec3 Particle::getVelocity(){ return velocity; }

    void Particle::setVelocity(Vec3 velocity){ this->velocity = velocity; }

    Vec3 Particle::getAcceleration(){ return acceleration; }

    void Particle::setAcceleration(Vec3 acceleration){ this->acceleration = acceleration; }

    float Particle::getMass(){ return mass; }

    void Particle::setMass(float mass){ this->mass = mass; }

    void Particle::addForce(Vec3 force){
        aggregateForce += force; 
    }

    void Particle::integrate(float t){
        acceleration += aggregateForce;

        position += velocity * t + acceleration * t * t * 0.5; 

        velocity += acceleration * t; 

        aggregateForce = zeroVector;
    }
}