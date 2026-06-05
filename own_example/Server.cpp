#include "Server.hpp"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Constructors
Server::Server(const std::string& world_name):
	world(World(world_name))
	// world(world_name)	// It is the same to do both options
{
	socket_id = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_id == -1)
		throw std::runtime_error("Socket initialization failed!");
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_family = AF_INET;
	address.sin_port = htons(DEFAULT_PORT);
	if (bind(socket_id, (sockaddr *)&address, sizeof(address)) == -1)
		throw std::runtime_error("Socket binding failed!");
	if (listen(socket_id, MAX_CLIENTS) == -1)
		throw std::runtime_error("Socket connection stablishment failed!");
}

Server::~Server()
{
	close(socket_id);
}

// Operators
// Nothing required

// Getters and setters
int							Server::get_socket_id(void) const
{
	return (socket_id);
}

const sockaddr_in&			Server::get_address(void) const
{
	return (address);
}

std::list<Player>&			Server::get_player_list(void)
{
	return (player_list);
}

const std::list<Player>&	Server::get_player_list(void) const
{
	return (player_list);
}

const World&				Server::get_world(void) const
{
	return (world);
}

// Utils
// TODO
Player&	Server::connect_user(const std::string& name, int client_fd)
{
	std::lock_guard<std::mutex>	lock(mtx);
	for (Player& p: player_list)
	{
		if (p.get_name() == name)
		{
			if (p.is_connected())
				throw std::runtime_error("Name already in use");
			p.set_client_fd(client_fd);
			p.set_connected(true);
			return (p);
		}
	}
	player_list.push_back(Player(name, client_fd));
	return (player_list.back());
}

void	Server::close_connections(void)
{
	std::cout << "Closing server..." << std::endl;
	for (Player& player: player_list)
		player.disconnect();
}
