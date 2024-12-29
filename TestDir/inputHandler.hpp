#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "common.hpp"

/*
* The purpose of this static class is to receive user input through GLFW callbacks
* and forward them to handlers. No OpenGL code should be in this class
* Initialize must be called!
*/

class InputHandler {
	static void keyCallback(GLFWwindow*, int, int, int, int);
	static void cursorCallback(GLFWwindow*, double, double);
	static void mouseCallback(GLFWwindow*, int, int, int);
	static void scrollCallback(GLFWwindow*, double, double);
public:
	static void initialize(GLFWwindow*);
};

#endif //INPUTHANDLER_HPP