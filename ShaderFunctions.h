#ifndef SHADER_FUNCTIONS_H
#define SHADER_FUNCTIONS_H
#include <GL/glew.h>   
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace ShaderFunctions {
	unsigned int compileShader(GLenum type, const char* source);
	unsigned int createShader(const char* vsSource, const char* fsSource);

}

#endif // GLWF_FUNCTIONS_H
