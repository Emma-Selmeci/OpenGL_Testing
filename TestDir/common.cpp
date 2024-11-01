#include "common.hpp"

#define GL_ERROR(errMessage) ERROR(CONTEXT, "GL_Error at" << fileName << " on line " << line << " | " << errMessage << "\n\t" << message);

//Check for errors the OpenGL way, log and exit if needed
void glDebug(const char* fileName, const int line, const char* message) {
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR) {
		switch (errorCode) {
		case GL_INVALID_ENUM: GL_ERROR("GL invalid enum"); break;
		case GL_INVALID_VALUE: GL_ERROR("GL invalid value"); break;
		case GL_INVALID_OPERATION: GL_ERROR("GL invalid operation"); break;
		case GL_STACK_OVERFLOW: GL_ERROR("GL stack overflow"); break;
		case GL_STACK_UNDERFLOW: GL_ERROR("GL stack underflow"); break;
		case GL_OUT_OF_MEMORY: GL_ERROR("GL out of memory"); break;
		case GL_INVALID_FRAMEBUFFER_OPERATION: GL_ERROR("GL invalid framebuffer operation"); break;
		case GL_CONTEXT_LOST: GL_ERROR("GL context lost"); break;
		default: GL_ERROR("Unrecognized error with code " << errorCode);
		}
		exit(2);
	}
}