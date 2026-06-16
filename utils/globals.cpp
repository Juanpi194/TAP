#include "utils.hpp"

#ifdef DEBUG_BUILD
	LogLevel	current_level = LOG_DEBUG;
#else
	LogLevel	current_level = LOG_WARNING;
#endif