#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class Shader {
public:
	GLuint Program = NULL;
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	void Use();
	void setID(const GLchar* uniformName, GLuint val);
	void setFloat(const GLchar* uniformName, GLfloat val);
};

#endif