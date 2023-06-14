#include "World/World.hpp"
#include "Constants/Constants.hpp"

namespace HyperEngine{

    void World::addObject(Object* object){ sceneObjects.push_back(object); }

    void World::Step(float t){
        for(int i = 0; i < sceneObjects.size(); i++){
            sceneObjects[i]->force += sceneObjects[i]->mass * gravity;
            sceneObjects[i]->velocity += sceneObjects[i]->Force / sceneObjects[i]->mass * t;
            sceneObjects[i]->position += sceneObjects[i]->velocity * t;

            sceneObjects[i]->force = zeroVector;
        }
    }

}