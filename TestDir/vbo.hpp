#ifndef VBO_HPP
#define VBO_HPP

#include "common.hpp"

class VBO {
	GLuint name;
public:
	VBO() { glGenBuffers(1, &name); }
	~VBO() { glDeleteBuffers(1, &name); }
	void bind() { glBindBuffer(GL_ARRAY_BUFFER, name); }
	operator GLuint() { return name; }
};

#endif