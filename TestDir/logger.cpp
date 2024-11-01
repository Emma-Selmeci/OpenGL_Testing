#include "logger.hpp"

#ifdef NDEBUG

#include <fstream>
#include <iostream>

Logger Logger::loggers[4]{
	"Log/levellog.txt","Log/context.txt","Log/startup.txt","Log/exit.txt",
}; //temp

Logger::Logger(const char* filename) : filename(filename) {}

void Logger::init() {
	std::cout << "Atexit called\n";
	atexit(Logger::exitCall);
}

void Logger::exitCall() {
	for (int i = 0; i < 4; ++i) {
		std::ofstream stream{ loggers[i].filename };
		stream << loggers[i].ss.rdbuf();
		stream.close();
	}
}

#endif