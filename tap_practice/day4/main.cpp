#include "Server.hpp"
#include "tap_commands.hpp"
#include <iostream>
#include <thread>
#include <cstring>
#include <unistd.h>

static bool	is_command(const std::string& s)
{
	if (s == "CONNECT")
		return (true);
	// TODO
	return (false);
	// return (s == "CONNECT" ||
	// 		s == "LOOK" ||
	// 		s == "");
}

static bool	is_event(const std::string& s)
{
	// TODO
	return (false);
}

static bool	is_error(const std::string& s)
{
	if (s == "NAME IN USE")
		return (true);
	// TODO
	return (false);
}

void	handle_msg(const std::string& msg, Player& sender, Server& server)
{
	const int			pos = msg.find(" ");
	const std::string	first_word = msg.substr(0, pos);
	Command				command;
	Event				event;
	Error				error;

	std::cout << pos << std::endl;
	std::cout << "Original line: " << msg << std::endl;
	std::cout << "Given command: " << first_word << std::endl;
	if (is_command(first_word))
	{
		command = str_to_command(first_word);
		std::cout << "Right command" << std::endl;
        return;
	}
	else if (is_event(first_word))
	{
		event = str_to_event(first_word);
		std::cout << "Right event" << std::endl;
        return;
	}
	else if (is_error(first_word))
	{
		error = str_to_error(first_word);
		std::cout << "Right error" << std::endl;
        return;
	}
	else
		throw std::invalid_argument("Wrong input");
}

// Thread function
void	player_routine(Player& player, Server& server)
{
	const int	fd = player.get_fd();
	ssize_t		bytes;
	char		buffer[MAX_MSG_LEN];
	std::string	msg;
	std::string	welcome_message;

	if (player.get_name().empty())
	{
		while (!player.ask_name())
			send(fd, "Error\n", sizeof("Error\n"), 0);
	}
	std::cout << "Player " << player.get_name() << " joined!" << std::endl;
	welcome_message = "Welcome, " + player.get_name() + "!\n";
	if (send(player.get_fd(), welcome_message.c_str(), welcome_message.size(), 0) == 1)
		throw std::exception();
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
			msg = std::string(buffer, bytes - 1);
			try
			{
				handle_msg(msg, player, server);
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << std::endl;
			}
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
