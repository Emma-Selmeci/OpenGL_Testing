#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <fstream>
#include <cassert>

#include <glew.h>
#include <glfw3.h>

void glDebug(const char*, const int, const char*);
void criticalError(const char*, const int, const char*);

/*
Logging is currently macro-based. Regular logging defines are:
WARNING_LOG | WARNING()
TRACE_LOG | TRACE()

CRITICAL() is for unrecoverable cases and are active even in Release mode
CRITICAL() calls also terminate by calling exit()

You can also set logging of the rendering loop with
RENDER_LOG | RLOG()

OpenGL error logging is always active in DEBUGMODE
*/

#define WARNING_LOG

#ifndef NDEBUG

	#ifdef RENDER_LOG
		#define RLOG(logMessage)
	#endif

	#ifdef WARNING_LOG
		#define WARNING(logMessage)
	#endif

	#ifdef TRACE_LOG
		#define WARNING(logMessage)
		#define TRACE(logMessage)
	#endif

	#define debugcall(a) a; glDebug(__FILE__, __LINE__, #a);

#else
	#define debugcall(a) a;
#endif

#ifdef RLOG(logMessage)
#define RLOG(logMessage) std::cout << "RENDERLOG: " << __FILE__ << ", line " << __LINE__ << " | " << logMessage << '\n';
#else
#define RLOG(logMessage)
#endif

#define CRITICAL(logMessage) criticalError(__FILE__,__LINE__,logMessage);

#ifdef WARNING(logMessage)
#define WARNING(logMessage) std::cout << "WARNING: " << __FILE__ << ", line " << __LINE__ << " | " << logMessage << '\n';
#else
#define WARNING(logMessage)
#endif

#ifdef TRACE(logMessage)
#define TRACE(logMessage) std::cout << "TRACE: " << fileName << ", line " << __LINE__ << " | " << logMessage << '\n';
#else
#define TRACE(logMessage)
#endif

#endif