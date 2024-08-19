#include "common.hpp"

#define errorMessage(errMessage) std::cout << "Error at " << fileName << " on line " << line << " | " << errMessage << "\n\t" << message << '\n';

void glDebug(const char* fileName, const int line, const char* message) {
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR) {
		switch (errorCode) {
		case 1281: errorMessage("Invalid enum"); break;
		default: errorMessage("Unrecognized error with code " << errorCode);
		}
	}
	exit(1);
}
