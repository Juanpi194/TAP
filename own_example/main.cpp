#include <iostream>
#include <thread>

#include "Server.hpp"

static void	send_msg(const std::string& str, int client_fd)
{
	if (send(client_fd, str.c_str(), str.size(), 0) == -1)
		throw std::runtime_error("Problem while sending " + str);
}

static void	player_routine(int client_fd, const World& world)
{
	const std::string	insert_name_msg = "Insert your name: ";
	char				buffer[MAX_MSG_LEN];
	ssize_t				bytes;

	send_msg(insert_name_msg, client_fd);
	bytes = recv(client_fd, buffer, MAX_MSG_LEN, 0);
	if (bytes == -1)
		throw std::runtime_error("Message sent by client failed");
	if (bytes == 0)
		return ;
	// while (std::string(buffer, bytes).empty())
	// {
	// 	send_msg()
	// }
	// Look for existing players with the name, ...
}

static void main_loop(Server *server)
{
	int client_fd;
	sockaddr address;		// Not used
	socklen_t address_len;	// Not used

	if (!server)
		return ;
	address_len = sizeof(address);
	while (true)
	{
		client_fd = accept(server->get_socket_id(), &address, &address_len);
		if (client_fd == -1)
			throw std::runtime_error("Client connection failed...");
		std::thread	client(player_routine, client_fd, std::ref(server->get_world()));
		client.detach();
	}
}

int main(void)
{
	const std::string world_name = "Amazing world of Gumball";
	Server server(world_name);

	std::cout << "Server initialized! World name: " << server.get_world().get_name() << std::endl;
	main_loop(&server);
	return (0);
}
