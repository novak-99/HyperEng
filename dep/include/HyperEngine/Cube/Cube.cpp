#include "Square.hpp"
#include "Constants/Constants.hpp"

#include <iostream>
#include <cmath>

namespace HyperEngine{
    Square::Square(float mass, float sideLength) : Particle(mass){ 
        this->mass = mass; 
        this->sideLength = sideLength; 
    }

    Square::Square(Vec3 position, Vec3 velocity, Vec3 acceleration, float mass, float sideLength) : Particle(position, velocity,  acceleration, mass){
        this->position = position;
        this->velocity = velocity;
        this->acceleration = acceleration;

        this->mass = mass;
        this->sideLength = sideLength;
    }

    float Square::getSideLength(){ return sideLength; }

    void Square::setSideLength(float sideLength){ this->sideLength = sideLength; }

    float Square::volume(){
        return std::pow(sideLength, 3);
    }

}