#include <iostream>
#include <thread>
#include <cstring>

#include "Server.hpp"
#include "utils.hpp"

static std::string	ask_name(int client_fd)
{
	const std::string	insert_name_msg = "Insert your name: ";
	char				buffer[MAX_MSG_LEN];
	ssize_t				bytes;
	std::string			name;

	bytes = 0;
	do
	{
		send_msg(insert_name_msg, client_fd);
		bytes = recv(client_fd, buffer, MAX_MSG_LEN, 0);
		if (bytes == -1)
			throw std::runtime_error("Message sent by client failed");
		if (bytes == 0)
			return ("");
		name = std::string(buffer, bytes);
		trim_newlines(name);
	} while (name.empty());
	return (name);
}

static void	player_routine(Player& player, Server& server)
{
	const std::string	welcome_msg = "Welcome, ";
	char				buffer[MAX_MSG_LEN];
	ssize_t				bytes;
	std::string			msg;
	Quest				quest("Send your first message");

	std::cout << "Player " << player.get_name() << " connected!" << std::endl;
	player.show_player_info();
	send_msg(welcome_msg + player.get_name() + "\n", player.get_client_fd());
	player.add_quest(quest);
	while (true)
	{
		memset(buffer, 0, MAX_MSG_LEN);
		bytes = recv(player.get_client_fd(), buffer, MAX_MSG_LEN, 0);
		if (bytes == -1)
			throw std::runtime_error("Message sent by client failed");
		if (bytes == 0)
			break ;
		msg = std::string(buffer, bytes);
		trim_newlines(msg);
		std::cout << player.get_name() << ": " << msg << std::endl;
		player.increment_sent_messages();
	}
}

static void	user_connection(int client_fd, Server& server)
{
	std::string	name;
	Player		*player;

	player = nullptr;
	do
	{
		name = ask_name(client_fd);
		if (name.empty())
		{
			close(client_fd);
			return ;
		}
		try
		{
			player = &server.connect_user(name, client_fd);
		}
		catch (const std::runtime_error& e)
		{
			send_msg(std::string(e.what()) + "\n", client_fd);
		}
	} while (!player);
	player_routine(*player, server);
	player->disconnect();
	return ;
}

static void main_loop(Server& server)
{
	int client_fd;
	sockaddr address;		// Not used
	socklen_t address_len;	// Not used

	// TODO: Add server owner, and create a thread that manages everything
	address_len = sizeof(address);
	while (true)
	{
		client_fd = accept(server.get_socket_id(), &address, &address_len);
		if (client_fd == -1)
			throw std::runtime_error("Client connection failed...");
		std::thread	client(user_connection, client_fd, std::ref(server));
		client.detach();
	}
	server.close_connections();
	close(server.get_socket_id());
}

int main(void)
{
	const std::string	world_name = "Amazing world of Gumball";
	const std::string	server_init_msg = "Server initialized! World name: ";
	Server server(world_name);

	std::cout << server_init_msg;
	std::cout << get_colored_str(server.get_world().get_name(), Color::CYAN);
	std::cout << std::endl;
	main_loop(server);
	return (0);
}
