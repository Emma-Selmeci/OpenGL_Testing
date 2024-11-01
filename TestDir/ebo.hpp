#ifndef EBO_HPP
#define EBO_HPP

#include "common.hpp"

class EBO {
	GLuint name;
public:
	EBO() { glGenBuffers(1, &name); }
	~EBO() { glDeleteBuffers(1, &name); }
	void bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, name); }
	operator GLuint() { return name; }
};

#endif