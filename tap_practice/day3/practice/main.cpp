#include "Server.hpp"
#include <iostream>
#include <thread>
#include <cstring>
#include <unistd.h>

void	handle_msg(const std::string& msg, Player& sender, Server& server)
{
	if (msg.find("/msg") == 0) // Empieza por /msg
	{
		const std::string	content = msg.substr(5);
		const int			pos = content.find(" ");
		const std::string	target = content.substr(0, pos);	// Target player name
		const std::string	private_msg = sender.get_name() + ": " + content.substr(pos + 1);
		const std::string	client_not_found_msg = "Player " + target + " is not in the list";
		const Player		*found_player = NULL;
		for (const Player& player: server.get_player_list())
		{
			if (player.get_name().compare(target.c_str()) == 0)
				found_player = &player;
		}
		if (found_player)
			server.private_msg(private_msg, sender, *found_player);
		else
			send(sender.get_fd(), "Player not in the list, try again\n", sizeof("Player not in the list, try again\n"), 0);
	}
	else
	{
		const std::string	public_msg = sender.get_name() + ": " + msg;
		server.public_msg(msg, sender);
	}
}

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
		server.add_player(Player(client_fd));
		std::thread	client(player_routine, std::ref(server.get_player_list().back()), std::ref(server));
		client.detach();
	}
	close(server.get_sock());
	return (0);
}
