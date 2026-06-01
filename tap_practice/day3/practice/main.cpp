#include "Server.hpp"
#include <iostream>
#include <thread>
#include <cstring>
#include <unistd.h>

// bool private_msg(int sender_fd, std::string &msg, std::list<int> &client_list, std::mutex &mtx)
// {
// 	const std::string	content = msg.substr(5);
// 	const int			pos = content.find(" ");
// 	const int			target_fd = std::stoi(content.substr(0, pos));
// 	const std::string	private_msg = std::to_string(sender_fd) + ": " + content.substr(pos + 1);
// 	const std::string	client_not_found_msg = "Client " + std::to_string(target_fd) + " is not in the list";

// 	for (int client_fd: client_list)
// 	{
// 		if (client_fd == target_fd)
// 		{
// 			if (send(client_fd, private_msg.c_str(), private_msg.size(), 0) == -1)
// 				throw std::exception();
// 			return true;
// 		}
// 	}
// 	if (send(sender_fd, client_not_found_msg.c_str(), client_not_found_msg.size(), 0) == -1)
// 		throw std::exception();
// 	return false;
// }

// void broadcast(int sender_fd, std::list<int> &client_list, std::mutex &mtx, const std::string &msg)
// {
// 	std::lock_guard<std::mutex> lock(mtx);
// 	for (int client : client_list)
// 	{
// 		if (sender_fd == client)
// 			continue;
// 		if (send(client, msg.c_str(), msg.size(), 0) == -1)
// 			std::cout << "Client '" << client << "' did not receive the msg" << std::endl;
// 	}
// }

// void	handle_msg(const std::string& msg, Player& player, Server& server)
// {
// 	if (msg.find("/msg") == 0) // Empieza por /msg
// 		private_msg(client_fd, msg, client_list, mtx);
// 	else
// 		broadcast(client_fd, client_list, mtx, std::string(buffer, bytes));
// }

// Thread function
void	player_routine(Player& player, Server& server)
{
	const int	fd = player.get_fd();
	ssize_t		bytes;
	char		buffer[MAX_MSG_LEN];
	std::string	msg;

	if (player.get_name().empty())
	{
		while (!player.ask_name())
			send(fd, "Error\n", sizeof("Error\n"), 0);
	}
	while (true)
	{
		memset(buffer, 0, sizeof(buffer));
		bytes = recv(fd, buffer, MAX_MSG_LEN, 0);
		if (bytes == 0)
			break;
		else if (bytes == -1)
			send(fd, "Error at sending message, try again\n", sizeof("Error at sending message, try again\n"), 0);
		else
		{
			msg = std::string(buffer, bytes);
			handle_msg(msg, player, server);
		}
	}
	server.remove_player(player);
	close(player.get_fd());
	std::cout << "Player '" << player.get_name() << "' disconnected" << std::endl;
}

int main(void)
{
	Server	server;
	int		client_fd;

	while (true)
	{
		client_fd = accept(server.get_sock(), nullptr, nullptr);
		if (client_fd == -1)
		{
			std::cout << "No more clients can be accepted / Unexpected error" << std::endl;
			continue;
		}
		Player	p(client_fd);
		server.add_player(p);
		std::thread	client(player_routine, std::ref(p), std::ref(server));
		client.detach();
	}
	close(server.get_sock());
	return (0);
}
