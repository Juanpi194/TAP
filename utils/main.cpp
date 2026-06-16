#include "utils.hpp"

int main(void)
{
	log("This is a debug msg", LogLevel::LOG_DEBUG);
	log("This is a warning", LogLevel::LOG_WARNING);
	log("This is an error", LogLevel::LOG_ERROR);
	return (0);
}
