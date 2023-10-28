#include "Particle/Particle.hpp"
#include "Sphere/Sphere.hpp"
#include "Vec3/Vec3.hpp"
#include <vector>

namespace HyperEngine{

    class World{
        private:
            std::vector<Sphere*> objects; 

        public:
            void addObj(Sphere* particle);
            void removeObj(Sphere* particle);

            std::vector<Sphere*> getObjects();

            void checkSphereCollison();
            void handleSphereInterpenetration(int i, int j, Vec3 posDiff, float distance, float radiusSum);
            void handleSphereCollision(int i, int j, Vec3 contactNormal, float restitution);
    };
}