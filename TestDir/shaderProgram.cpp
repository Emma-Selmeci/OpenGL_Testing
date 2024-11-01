#include "shaderProgram.hpp"

void ShaderProgram::validateProgram(GLint programId) {
	GLint status;
	glGetProgramiv(programId, GL_LINK_STATUS, &status);
	if (status == GL_TRUE) {
		TRACE(STARTUP, "Program linked successfully");
	}
	else {
		char buffer[512];
		glGetProgramInfoLog(programId, 512, NULL, buffer);
		ERROR(STARTUP, "Program link error " << buffer);
	}

	glValidateProgram(programId);
	glGetProgramiv(programId, GL_VALIDATE_STATUS, &status);
	if (status == GL_TRUE) {
		TRACE(STARTUP, "Program validated");
	}
	else {
		char buffer[512];
		glGetProgramInfoLog(programId, 512, NULL, buffer);
		ERROR(STARTUP, "Program invalid " << buffer);
	}
}

ShaderProgram::ShaderProgram(GLuint shader1, GLuint shader2) {
	TRACE(STARTUP, "Creating program object and attaching shaders...");

	name = glCreateProgram();
	if (name == 0) ERROR(STARTUP, "program object generation failed");

	debugcall(glAttachShader(name, shader1));
	debugcall(glAttachShader(name, shader2));
	
	debugcall(glLinkProgram(name));

	validateProgram(name);
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(name);
}
