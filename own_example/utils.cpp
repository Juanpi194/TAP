#include "utils.hpp"
#include <iostream>
#include <netinet/in.h>

void	send_msg(const std::string& str, int client_fd)
{
	if (send(client_fd, str.c_str(), str.size(), 0) == -1)
		throw std::runtime_error("Problem while sending " + str);
}
