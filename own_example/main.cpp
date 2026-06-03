#include <iostream>

#include "Server.hpp"

int	main(void)
{
	const std::string	world_name = "Amazing world of Gumball";
	Server	*server;

	server = new Server(world_name);
	std::cout << "Server initialized! World name: " << server->get_world().get_name() << std::endl;
	delete (server);
	return (0);
}
