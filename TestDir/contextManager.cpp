#include "contextManager.hpp"

void ContextManager::myCallBack(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam) {
    std::string str;
    str.append(message, length);
    ERROR(CONTEXT, "GL Error " << source << ' ' << type << ' ' << id << ' ' << severity << ' ' << str);
}

GLFWwindow* ContextManager::genContext() {
    //This method could be further improved by providing detailed error feedback
	INFO(CONTEXT, "Generating GLFW context and initializing GLEW");

	if (!glfwInit()) { 
		ERROR(CONTEXT, "Failed to initialize GLFW context");
	}

    //glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE); //Needed for automatic debugging
    GLFWwindow* window = glfwCreateWindow(600, 600, "Hello World", NULL, NULL);
    if (!window) {
        ERROR(CONTEXT, "Failed to create window");
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        ERROR(CONTEXT, "Failed to initialize GLEW");
    }
    
    //glDebugMessageCallback(myCallBack, nullptr);

    INFO(CONTEXT, "Successfully created GLFW context and initialized GLEW  ");
    return window;
}
