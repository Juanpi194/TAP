#include "Server.hpp"

// Constructors ---------------------------------------------------------------
Server::Server()
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		std::cout << "Socket initialization failed!" << std::endl;
		throw std::exception();
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);
	if (bind(sock, (sockaddr *)&address, sizeof(address)) == -1)
	{
		std::cout << "Socket binding failed!" << std::endl;
		throw std::exception();
	}
	if (listen(sock, MAX_PLAYERS) == -1)
	{
		std::cout << "Socket listen failed!" << std::endl;
		throw std::exception();
	}
}

Server::~Server()
{
}

// Operators ------------------------------------------------------------------
// TODO

// Getters
int Server::get_sock() const
{
	return (sock);
}

const std::list<Player> &Server::get_player_list() const
{
	return (player_list);
}

// Setters --------------------------------------------------------------------
// TODO

// Utils
bool Server::private_msg(const std::string &msg, const Player &sender, const Player &target)
{
	std::lock_guard<std::mutex> lock(mtx);
	for (Player& player : player_list)
	{
		if (player.get_id() == target.get_id())
		{
			if (send(player.get_fd(), msg.c_str(), msg.size(), 0) == -1)
			{
				std::cout << sender.get_name() << " tried to send a message to " << target.get_name() << ", but failed!";
				throw std::exception();
			}
			return (true);
		}
	}
	std::cout << sender.get_name() << " tried to send a message to " << target.get_name() << ", but that player is not in the server!";
	return (false);
}

void Server::public_msg(const std::string &msg, const Player &sender)
{
	std::lock_guard<std::mutex> lock(mtx);
	for (Player& player : player_list)
	{
		if (send(player.get_fd(), msg.c_str(), msg.size(), 0) == -1)
		{
			std::cout << sender.get_name() << " tried to send a message to " << player.get_name() << ", but failed!";
			throw std::exception();
		}
	}
}

void Server::add_player(const Player &player)
{
	std::lock_guard<std::mutex> lock(mtx);
	player_list.push_back(player);
}

bool Server::remove_player(const Player &target)
{
	const size_t before = player_list.size();

	std::lock_guard<std::mutex> lock(mtx);
	player_list.remove(target);
	return (player_list.size() < before);	// true if changed, false otherwise
}
