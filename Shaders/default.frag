#version 330 core

uniform samplerCube tex0;


out vec4 fragColor;
in vec3 color; 
in vec3 texCoords;


void main(){
    //fragColor = texture(tex0, texCoords);
    fragColor = vec4(color, 1.0f); 
} 