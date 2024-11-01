#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include "common.hpp"

class ShaderProgram {
	GLuint name;
	static void validateProgram(GLint);
public:
	ShaderProgram(GLuint, GLuint);
	ShaderProgram();
	~ShaderProgram();
	void use() { glUseProgram(name); }
	operator GLuint() { return name; }
};

#endif //SHADERPROGRAM_HPP