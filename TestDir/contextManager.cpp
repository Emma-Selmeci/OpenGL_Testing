#include "contextManager.hpp"

GLFWwindow* ContextManager::genContext() {
    //This method could be further improved by providing detailed error feedback
	TRACE("Generating GLFW context and initializing GLEW");

	if (!glfwInit()) { 
		CRITICAL("Failed to initialize GLFW context");
	}

    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        CRITICAL("Failed to create window");
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        CRITICAL("Failed to initialize GLEW");
    }

    TRACE("Successfully created GLFW context and initialized GLEW  ");
    return window;
}
