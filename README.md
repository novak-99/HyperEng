# HyperEngine

A C++ particle physics engine. 

## Contents 

Supports various constant acceleration physics operations, sphere objects and collisions. 

## Demo 

## How to Run 

Must install glad, GLFW, GLM, STB. 

Library can be compiled by running:

```
g++ -Wall -O2 -std=c++17 -g -I shaders -I dep/include -I glad -I stb -I dep/include/HyperEngine -I include \
    -L dep/lib main.cpp stb.cpp glad.c dep/lib/libglfw.3.3.dylib dep/include/HyperEngine/Particle/Particle.cpp dep/include/HyperEngine/Vec3/Vec3.cpp dep/include/HyperEngine/World/World.cpp dep/include/HyperEngine/Sphere/Sphere.cpp src/ShaderSource.cpp -o main.o \
    -framework OpenGL -framework Cocoa -framework IOKit \
    -framework CoreVideo -framework CoreFoundation \
    -Wno-deprecated
```
