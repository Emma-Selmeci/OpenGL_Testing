#ifndef SHADER_HPP
#define SHADER_HPP

#include "common.hpp"

class Shader {
private:
	GLuint name;
	static GLenum getShaderType(std::string&);
	static void validateShader(GLint);
public:
	Shader(const char* filePath);
	~Shader();
	operator GLuint() { return name; }
};

#endif //SHADER_HPP