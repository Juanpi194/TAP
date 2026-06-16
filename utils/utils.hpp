#pragma once
#include <string>

enum LogLevel {LOG_NONE, LOG_ERROR, LOG_WARNING, LOG_INFO, LOG_DEBUG};


extern LogLevel	current_level;

/*
@brief		Prints the given text if the log level is accepted in the
			specified level. If no level is specified, current log level
			of the program will be used.

@param		msg		Message to be printed.
@param		level	Log level to print `msg`.
@example	log("Hello", LogLevel::LOG_ERROR);

@note		All logs will be printed in the `cerr` (2).
*/
void	log(const std::string& msg, LogLevel level = current_level);

/*
@brief		All space characters at the beginning and at the end will be removed.
			Available characters to remove:
				
			- ' ' (Space)

			- '\n' (New line)

			- '\r' (Carriage return)

			If it is specified, characters in the middle of the string will be
			removed as well.

@param		s		Reference to the string to trim.
@param		middle	Set as `true` by default. If `true`, space characters
			in the middle of the string will be removed too. Otherwise,
			only characters at the end and at the beginning will be removed.

@example	trim_str(" hello    world    ") -> s = "hello world"
			trim_str(" hello    world    ", false) -> s = "hello    world"
*/
void	trim_str(std::string& s, bool middle = true);
