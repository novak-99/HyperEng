#include <iostream>
#include "World.hpp"
#include "Vec3/Vec3.hpp"
#include <set>

namespace HyperEngine{
    void World::addObj(Sphere* particle){
        objects.push_back(particle);
    }
    
    void World::removeObj(Sphere* particle){
        objects.erase(std::remove(objects.begin(), objects.end(), particle), objects.end());
    }

    std::vector<Sphere*>  World::getObjects(){
        return objects;
    }

    void World::checkSphereCollison(){
        std::set<int> usedObjects; 
        for(int i = 0; i < objects.size(); i++){
            for(int j = 0; j < objects.size(); j++){
                if(i == j) continue;
                if(usedObjects.find(i) != usedObjects.end() || usedObjects.find(j) != usedObjects.end()) continue; 

                Vec3 posDiff = objects[i]->getPosition() - objects[j]->getPosition();
                float distance = std::sqrt(posDiff.getIComponent() * posDiff.getIComponent() + posDiff.getJComponent() * posDiff.getJComponent() + posDiff.getKComponent() * posDiff.getKComponent());
                float radiusSum = objects[i]->getRadius() + objects[j]->getRadius();

                
                if(distance < radiusSum){

                    handleSphereInterpenetration(i, j, posDiff, distance, radiusSum);
                    usedObjects.insert(i);
                    usedObjects.insert(j);
                    std::cout << "In collision.." << "\n";
                    handleSphereCollision(i, j, posDiff.normalize(), 0.5);
                }
            }
        }
    }

    // void World::handleSphereCollision(int i, int j, Vec3 contactNormal, float restitution){
    //     float separatingVelocity = (objects[i]->getVelocity() - objects[j]->getVelocity()) * contactNormal;
    //     float newSeparatingVelocity = -separatingVelocity * restitution;

    //     float velocityChange = newSeparatingVelocity - separatingVelocity;

    //     float mass1 = objects[i]->getMass();
    //     float mass2 = objects[j]->getMass();
    //     float totalMass = 1 / (1/mass1 + 1/mass2);

    //     Vec3 impulse = contactNormal * velocityChange;

    //     std::cout << totalMass << "\n";
    //     Vec3 impulse1 = impulse * totalMass / mass1;
    //     Vec3 impulse2 = impulse * totalMass / mass2;


    //     objects[i]->setVelocity(objects[i]->getVelocity() + impulse1);

    //     objects[j]->setVelocity(objects[j]->getVelocity() - impulse2);

    //     std::cout << "NEW VEL" << "\n";
    //     std::cout << i << "\n";
    //     objects[i]->getVelocity().print();
    //     std::cout << mass1 << "\n";

    //     std::cout << "NEW VEL" << "\n";
    //     std::cout << j << "\n";
    //     objects[j]->getVelocity().print();
    //     std::cout << mass2 << "\n";
    // }


    void World::handleSphereCollision(int i, int j, Vec3 contactNormal, float restitution){        
        Vec3 relativeVelocity = objects[j]->getVelocity() - objects[i]->getVelocity(); 
        
        float dotProduct = relativeVelocity * contactNormal; 
        
        float impulse = (-(1.0f + restitution) * dotProduct) / (1.0f / objects[i]->getMass() + 1.0f / objects[j]->getMass());
            
        objects[i]->setVelocity(objects[i]->getVelocity() - contactNormal * (impulse / objects[i]->getMass()));
            
        objects[j]->setVelocity(objects[j]->getVelocity() + contactNormal * (impulse / objects[j]->getMass()));
    }

    void World::handleSphereInterpenetration(int i, int j, Vec3 posDiff, float distance, float radiusSum){
        double overlap = radiusSum - distance;

        Vec3 separationVec = posDiff * (overlap / distance); 

        objects[i]->setPosition(objects[i]->getPosition() + separationVec / 2); 
        objects[j]->setPosition(objects[j]->getPosition() - separationVec / 2); 
    }
}