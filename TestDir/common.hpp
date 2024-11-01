#ifndef COMMON_HPP
#define COMMON_HPP

#include <cassert>
#include <iostream>
#include <sstream>

//Varied debugger for debug and release
#ifdef NDEBUG
	#include "logger.hpp"
#else
	#include "debugLogger.hpp"
#endif

#include <glew.h>
#include <glfw3.h>

//These two test gl calls for bugs and log them if need be
void glDebug(const char*, const int, const char*);
#ifdef NDEBUG
	#define debugcall(a) a;
#else
	#define debugcall(a) a; glDebug(__FILE__, __LINE__, #a);
#endif

#endif