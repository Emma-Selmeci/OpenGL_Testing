#ifndef CONTEXTMANAGER_HPP
#define CONTEXTMANAGER_HPP

#include "common.hpp"

/*
This class is used for window generation and hopefully callback functions later

I've decided not to use the automatic gl error callback as it doesn't specify where an error occurs. 
*/

class ContextManager {
public:
	static void myCallBack(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
	static GLFWwindow* genContext();
};

#endif