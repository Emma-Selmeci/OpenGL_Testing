#ifndef DEBUGLOGGER_HPP
#define DEBUGLOGGER_HPP

#include <iostream>

#ifndef NDEBUG
#define TRACE(type, args) {if(Logger::canLog(Logger::LOGTYPE::##type,Logger::LOGLEVEL::TRACE)) {Logger::log(Logger::LOGTYPE::##type) << "\nTrace : " args;}}
#define INFO(type, args) {if(Logger::canLog(Logger::LOGTYPE::##type,Logger::LOGLEVEL::INFO)) {Logger::log(Logger::LOGTYPE::##type) << "\nInfo : " args;}}
#define WARN(type, args) {if(Logger::canLog(Logger::LOGTYPE::##type,Logger::LOGLEVEL::WARN)) {Logger::log(Logger::LOGTYPE::##type) << "\nWarn : " args;}}
#define CRITICAL(type, args) {if(Logger::canLog(Logger::LOGTYPE::##type,Logger::LOGLEVEL::CRITICAL)) {Logger::log(Logger::LOGTYPE::##type) << "\nCritical : " args;}}
#define ERROR(type, args) {if(Logger::canLog(Logger::LOGTYPE::##type,Logger::LOGLEVEL::ERROR)) {Logger::log(Logger::LOGTYPE::##type) << "\nError : " args;} exit(1);}

#define LOGLEVEL(type, level) Logger::setLogLevel(Logger::LOGTYPE::##type, Logger::LOGLEVEL::##level);

class Logger {
	enum LOGLEVEL;
private:
	static Logger loggers[4]; //4 default-constructed Loggers
	LOGLEVEL level;
	Logger() : level(TRACE) {};
public:
	static void init() {} //For compatibility with logger
	enum LOGLEVEL {
		TRACE = 0, INFO, WARN, CRITICAL, ERROR,
	};
	enum LOGTYPE {
		LEVEL = 0, CONTEXT, STARTUP, EXIT //Values would've been defined to start from 0 anyways
	};

	static bool canLog(LOGTYPE type, LOGLEVEL level) {
		//std::cout << (loggers[type].level) << '\n';
		//std::cout << (loggers[type].level <= level) << '\n';
		return loggers[type].level <= level;
	}
	static Logger& log(LOGTYPE type) { return loggers[type]; }
	
	static void setLogLevel(LOGTYPE type, LOGLEVEL level) {
		loggers[type].level = level;
	}

	template<typename C>
	Logger& operator<< (C c) {
		std::cout << c; return *this;
	}

	//Deleting copy and move constructors and assignments to avoid user making copies
	Logger(const Logger&) = delete;
	Logger operator= (const Logger&) = delete;
	Logger(Logger&&) = delete;
	Logger operator= (Logger&&) = delete;
};

#endif

#endif