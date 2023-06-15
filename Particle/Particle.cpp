#include "Particle/Particle.hpp"
#include "Constants/Constants.hpp"

namespace HyperEngine{

    Particle::Particle(){ }

    Particle::Particle(float mass){
        this->mass = mass; 

        this->force = zeroVector; 
        this->velocity = zeroVector;
        this->position = zeroVector;
    }

    Particle::Particle(Vector3 position, Vector3 velocity, Vector3 acceleration, float mass){
        this->force = gravity;
        this->position = position;
        this->velocity = velocity;
        this->acceleration = acceleration;
    }

    Particle::Particle(Vector3 force, Vector3 position, Vector3 velocity, Vector3 acceleration, float mass){
        this->force = force;
        this->position = position;
        this->velocity = velocity;
        this->acceleration = acceleration;
    }

    void Particle::integrate(float duration){
        position.addScaledVector(velocity, duration);

        Vector3 imposedAcceleration = acceleration;
        imposedAcceleration.addScaledVector(forceAccum, inverseMass);

        velocity.addScaledVector(resultingAcc, duration);

        velocity *= powf(damping, duration);

    }

    Vector3 Particle::getForce(){
        return force; 
    }

    void Particle::setForce(Vector3 force){
        this->force = force;
    }

    Vector3 Particle::getPosition(){
        return position; 
    }

    void Particle::setPosition(Vector3 position){
        this->position = position;
    }

    Vector3 Particle::getVelocity(){
        return velocity;
    }

    void Particle::setVelocity(Vector3 position){
        this->velocity = velocity;
    }

    Vector3 Particle::getAcceleration(){
        return acceleration; 
    }

    void Particle::setAcceleration(Vector3 position){
        this->acceleration = acceleration;
    }

    float Particle::getInverseMass(){
        return inverseMass;
    }

    void Particle::setInverseMass(float inverseMass){
        this->inverseMass = inverseMass; 
    }

    float Particle::getMass(){
        return 1/inverseMass; 
    }

    void Particle::setMass(float mass){
        this->inverseMass = 1/inverseMass; 
    }

}