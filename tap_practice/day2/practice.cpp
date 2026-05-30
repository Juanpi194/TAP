#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <list>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <cstring>

struct	s_server
{
	int					sock;
	struct sockaddr_in	address;
	std::list<int>		client_fd_list;
};

class Player
{
	private:
		int			client_fd;
		int			id;
		std::string	name;
		static int	available_id;

	public:
		Player(void)
		{
			client_fd = 0;
			id = available_id;
			available_id++;
			this->name = "default";
		}

		Player(int client_fd, const std::string& name)
		{
			this->client_fd = client_fd;
			id = available_id;
			available_id++;
			this->name = name;
		}

		bool operator==(const Player& other) const
		{
			if (this == &other)
				return (true);
			return (false);
			// return (this == &other);	// Easiest way
		}

		int	get_client_fd(void) const
		{
			return (client_fd);
		}

		int	get_id(void) const
		{
			return (id);
		}

		const std::string&	get_name(void) const
		{
			return (name);
		}

		static int	get_available_id(void)
		{
			return (available_id);
		}

		void	set_client_fd(int client_fd)
		{
			if (client_fd < 0)
				return ;
			this->client_fd = client_fd;
		}

		void	set_name(const std::string& name)
		{
			if (name.empty())
				return ;
			this->name = name;
		}
};

int	Player::available_id = 0;

void	client_routine(Player& player, std::list<Player>& player_list, std::mutex& mtx)
{
	char		buffer[256];
	std::string	welcome_msg;
	int			bytes;

	send(player.get_client_fd(), "Insert your name: ", sizeof("Insert your name: "), 0);
	bytes = recv(player.get_client_fd(), buffer, 256, 0);
	if (bytes == 0)
	{
		std::cout << "Client '" << std::to_string(player.get_client_fd()) << "' disconnected before sending name" << std::endl;
		close(player.get_client_fd());
		player_list.remove(player);
		return ;
	}
	std::string name(buffer, bytes);
	name.erase(name.find_last_not_of("\n\r") + 1);	// Para borrar el salto de linea
	player.set_name(name);
	memset(buffer, 0, 256);
	std::cout << "Player " << player.get_name() << " joined" << std::endl;
	welcome_msg = "Welcome, " + player.get_name() + "!\n";
	send(player.get_client_fd(), welcome_msg.c_str(), welcome_msg.size(), 0);
	while (true)
	{
		bytes = recv(player.get_client_fd(), buffer, 256, 0);
		if (bytes == 0)
			break;
		std::cout << player.get_name() << ": " << buffer;
		memset(buffer, 0, 256);
	}
	std::cout << "Player '" << player.get_name() << "' disconnected" << std::endl;
	close(player.get_client_fd());
	player_list.remove(player);
}

int	main(void)
{
	int					sock;
	struct sockaddr_in	address;
	std::list<Player>	player_list;
	int					client_fd;
	std::mutex			mtx;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		throw std::exception();

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);
	if (bind(sock, (sockaddr *)&address, sizeof(address)) == -1)
		throw std::exception();

	if (listen(sock, 5) == -1)
		throw std::exception();

	while (true)
	{
		client_fd = accept(sock, nullptr, nullptr);
		if (client_fd == -1)
			throw std::exception();
		Player	p;	// Default constructor
		p.set_client_fd(client_fd);
		player_list.push_back(p);
		std::thread	client(client_routine, std::ref(player_list.back()), std::ref(player_list), std::ref(mtx));
		client.detach();
	}
	close(sock);
	return (0);
}
