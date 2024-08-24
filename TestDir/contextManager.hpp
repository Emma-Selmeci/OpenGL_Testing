#ifndef CONTEXTMANAGER_HPP
#define CONTEXTMANAGER_HPP

#include "common.hpp"

/*
This class is used for window generation and hopefully callback functions later
*/

class ContextManager {
public:
	static GLFWwindow* genContext();
};

#endif