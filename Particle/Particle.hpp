#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "Vector3.hpp"

namespace HyperEngine{

    class Particle{

        public:
            Vector3 position; 

            Vector3 velocity; 

            Vector3 acceleration; 

            float damping; 

        private: 


    };
}
#endif // PARTICLE_HPP