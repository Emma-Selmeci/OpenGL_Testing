#include "common.hpp"

#define GL_ERROR(errMessage) std::cout << "GL_Error at " << fileName << " on line " << line << " | " << errMessage << "\n\t" << message << '\n';

void glDebug(const char* fileName, const int line, const char* message) {
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR) {
		switch (errorCode) {
		case 1281: GL_ERROR("Invalid enum"); break;
		default: GL_ERROR("Unrecognized error with code " << errorCode);
		}
	}
	exit(1);
}
