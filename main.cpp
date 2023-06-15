using namespace HyperEngine; 

#include "Particle.hpp"
#include "Vector.hpp"
#include "Constants.hpp"

int main(){

    const Vector3 BULLET_POS = zeroVector;
    const Vector3 BULLET_VEL = Vector3(0.0, 0.0, 35.0);
    const Vector3 BULLET_ACC = Vector3(0.0, -1.0, 0.0);
    
    const float BULLET_MASS = 2.0; 
    const float BULLET_DAMP = 0.99; 


    Bullet* b = new Particle()


    delete b; 

    return 0; 
}