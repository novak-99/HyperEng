#version 330 core

layout (location = 0) in vec3 aPos; 
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex; 

uniform float scale; 

uniform mat4 model; 
uniform mat4 view; 
uniform mat4 proj; 

out vec3 color;
out vec3 texCoords;

void main(){
   gl_Position = proj * view * model * vec4(aPos, 1.0);
   color = aColor; 
   texCoords = vec3(aPos.x, aPos.y, aPos.z);
}