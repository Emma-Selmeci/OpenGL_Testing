#include "shader.hpp"
#include "common.hpp"

#include <fstream>
#include <sstream>

/*
This class takes as input a file that has the shader type in its first line

*/

GLenum Shader::getShaderType(std::string& str)
{
	if (str.find("vertex") != std::string::npos) return GL_VERTEX_SHADER;
	if (str.find("fragment") != std::string::npos) return GL_FRAGMENT_SHADER;
	ERROR(STARTUP, "Unknown shader type with string : " << str);
}

void Shader::validateShader(GLint shaderId) {
	GLint status;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);
	if (status == GL_TRUE) {
		TRACE(STARTUP, "Shader compiled successfully");
	}
	else {
		char buffer[512];
		glGetShaderInfoLog(shaderId, 512, NULL, buffer);
		ERROR(STARTUP, "Shader compile error " << buffer);
	}
}

//Shader can take the filename or the full filepath as an argument
//Maybe we should be able to identify without the file extension?
Shader::Shader(const char* filePath) {
	std::ifstream fin;
	if (strchr(filePath, '/') == nullptr) { //This is a full filepath (or is completely fucked up)
		std::string fName = "Res/Shaders/";
		fName.append(filePath); //I'm not sure if this is the fastest way to append
		fin.open(fName);
		TRACE(STARTUP, "attempting to open file with fname : " << fName);
	} else {
		fin.open(filePath);
		TRACE(STARTUP, "attempting to open file with fname : " << filePath);
	}

	if (!fin.is_open()) {
		ERROR(STARTUP, "failed to open file : " << filePath);
	}

	//This way of reading data can be heavily optimized but this will do for now
	std::string str;
	std::stringstream ss;
	getline(fin, str);
	GLenum shaderType = getShaderType(str); //Determining the shader type

	while (fin.good()) { //Reading data
		getline(fin, str);
		ss << str << '\n';
	}
	fin.close();
	str = ss.str();
	const char* shaderSource = str.c_str();

	//Setting up the shader
	name = glCreateShader(shaderType);
	debugcall(glShaderSource(name, 1, &shaderSource, NULL));
	debugcall(glCompileShader(name));
	validateShader(name);

}

Shader::~Shader() {
	glDeleteShader(name);
}
