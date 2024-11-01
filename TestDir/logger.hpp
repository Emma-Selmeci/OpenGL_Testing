#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <sstream>

/*
Logger with the goals of:
-Low overhead
-File IO
-Filtering

The logger has different behavior in Debug and Release mode to minimize overhead
DEBUG:
-Log levels can be changed
-Trace log level active
-Outputs to console
RELEASE:
-Maximum speed with minimal overhead
-Outputs to files
*/

#ifdef NDEBUG
#define TRACE(type, args)
#define INFO(type, args) Logger::log(Logger::LOGTYPE::##type) << "\nInfo : " args;
#define WARN(type, args) Logger::log(Logger::LOGTYPE::##type) << "\nWarn : " args;
#define CRITICAL(type, args) Logger::log(Logger::LOGTYPE::##type) << "\nCritical : " args;
#define ERROR(type, args) Logger::log(Logger::LOGTYPE::##type) << "\nError : " args; exit(1);

#define LOGLEVEL(type, level)

class Logger {
	enum LOGLEVEL;
private:
	std::stringstream ss; //Default initialized
	static void exitCall(); //Function to initiate file IO | To be sent to atexit()
	static Logger loggers[4]; //4 default-constructed Loggers
	const char* filename;
	Logger(const char* fileName);
public:
	static void init(); //To be called before exit()

	enum LOGTYPE {
		LEVEL = 0, CONTEXT, STARTUP, EXIT //Values would've been defined to start from 0 anyways
	};

	static Logger& log(LOGTYPE type) { return loggers[type]; }

	template<typename C>
	Logger& operator<< (C c) {
		ss << c; return *this;
	}

	//Deleting copy and move constructors and assignments to avoid user making copies
	Logger(const Logger&) = delete;
	Logger operator= (const Logger&) = delete;
	Logger(Logger&&) = delete;
	Logger operator= (Logger&&) = delete;
};

#endif

#endif