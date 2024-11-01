#ifndef VAO_HPP
#define VAO_HPP

#include "common.hpp"

class VAO {
	GLuint name;
public:
	VAO() { glGenVertexArrays(1, &name); }
	~VAO() { glDeleteVertexArrays(1, &name); }
	void bind() { glBindVertexArray(name); }
	operator GLuint() { return name; }
};

#endif