#pragma once
#include <string>
#include <unistd.h>

void	send_msg(const std::string& str, int client_fd);

enum Color
{
	RESET = 0,

	BLACK = 30,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	MAGENTA = 35,
	CYAN = 36,
	WHITE = 37,

	BRIGHT_RED = 91,
	BRIGHT_GREEN = 92,
	BRIGHT_YELLOW = 93,
	BRIGHT_BLUE = 94,
	BRIGHT_MAGENTA = 95,
	BRIGHT_CYAN = 96,
	BRIGHT_WHITE = 97
};

std::string	get_colored_str(const std::string& str, Color color);

void	trim_newlines(std::string& s);
