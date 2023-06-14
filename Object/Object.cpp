#include "Object/Object.hpp"
#include "Constants/Constants.hpp"

namespace HyperEngine{

    Object::Object(float mass){
        this->mass = mass; 

        this->force = zeroVector; 
        this->velocity = zeroVector;
        this->position = position;
    }

    Object::Object(Vector3 force, Vector3 velocity, Vector3 position, float mass){
        this->force = force;
        this->velocity = velocity;
        this->position = position;
    }

    Vector3 Object::getForce(){
        return force; 
    }

    Vector3 Object::getPosition(){
        return position; 
    }

    Vector3 Object::getVelocity(){
        return velocity;
    }

    float Object::getMass(){
        return mass; 
    }

}