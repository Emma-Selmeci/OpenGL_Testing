#include "inputHandler.hpp"

void InputHandler::initialize(GLFWwindow* window) {
	INFO(CONTEXT, "Setting up input callbacks");
	glfwSetKeyCallback(window, keyCallback);
	glfwSetCursorPosCallback(window, cursorCallback);
	glfwSetMouseButtonCallback(window, mouseCallback);
	glfwSetScrollCallback(window, scrollCallback);
}

void InputHandler::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_REPEAT) return; //We're not receiving text input
}

void InputHandler::cursorCallback(GLFWwindow* window, double xPos, double yPos) {
}

void InputHandler::mouseCallback(GLFWwindow* window, int button, int action, int mods) {

}

void InputHandler::scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
}