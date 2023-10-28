#include <fstream>
#include <iostream>
#include "ShaderSource.hpp"

std::string ShaderSource::readShaderSource(std::string filename){
    std::string content; 
    std::ifstream fileStream(filename);

    if(!fileStream.is_open()){
        std::cerr << "Problem opening with file " << filename << "." "\n";
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()){
        std::getline(fileStream, line);
        content.append(line + '\n');
    }

    fileStream.close();

    return content; 
}