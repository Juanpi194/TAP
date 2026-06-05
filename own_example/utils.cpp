#include "utils.hpp"
#include <iostream>
#include <netinet/in.h>

void	send_msg(const std::string& str, int client_fd)
{
	if (send(client_fd, str.c_str(), str.size(), 0) == -1)
		throw std::runtime_error("Problem while sending " + str);
}

std::string	get_colored_str(const std::string& str, Color color = Color::RESET)
{
	std::string	final_string;

	final_string += "\033[" + std::to_string(color) + "m" + str + "\033[0m";
	return (final_string);
}

void	trim_newlines(std::string& s)
{
    while (!s.empty() && (s.back() == '\n' || s.back() == '\r'))
        s.pop_back();
}

