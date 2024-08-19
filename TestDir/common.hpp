#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <glew.h>
#include <glfw3.h>

#include <iostream>
#include <fstream>

void glDebug(const char*, const int, const char*);

#ifdef DEBUGMODE
#define debugcall(a) a; glDebug(__FILE__, __LINE__, #a);
#else
	#define debugcall(a) a;
#endif

#endif