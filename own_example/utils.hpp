#pragma once
#include <string>
#include <unistd.h>

void	send_msg(const std::string& str, int client_fd);
