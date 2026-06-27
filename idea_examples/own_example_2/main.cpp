#include <iostream>
#include <string>
#include <list>
#include <unistd.h>
#include <atomic>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>

#include <thread>
#include <mutex>

constexpr unsigned int	MAX_PLAYERS = 20;
constexpr unsigned int	MAX_NAME_LENGTH = 15;
constexpr unsigned int	MAX_MSG_LENGTH = 256;
std::atomic<bool>		running = true;

void	trim_str(std::string& s, bool middle = true)
{
	std::string	result;

	// End
	while (!s.empty() && (s.back() == '\n' || s.back() == '\r' || s.back() == ' '))
		s.pop_back();
	// Beginning
	while (!s.empty() && (s.front() == '\n' || s.front() == '\r' || s.front() == ' '))
		s.erase(0, 1);
	// Removing duplicated in the middle
	if (!middle)
		return ;
	for (char c : s)
	{
		if (c != ' ')
			result += c;
		else if (result.back() != ' ')
			result += c;
	}
	s = result;
}

class ServerInitiationException final: public std::exception
{
	private:
		std::string	msg;
	public:
		// Constructors
		ServerInitiationException(void):
			msg("Server initiation failed")
		{
		}
		explicit ServerInitiationException(const std::string& msg):
			msg(msg)
		{
		}

		// Utils
		const char	*what(void) const noexcept override
		{
			return (msg.c_str());
		}
};

class PlayerInitiationException final: public std::exception
{
	private:
		std::string	msg;
	public:
		// Constructors
		PlayerInitiationException(void):
			msg("Player initiation failed")
		{
		}
		explicit PlayerInitiationException(const std::string& msg):
			msg(msg)
		{
		}

		// Utils
		const char	*what(void) const noexcept override
		{
			return (msg.c_str());
		}
};

class Server;

class Player
{
	private:
		int					client_fd;
		unsigned int		id;
		std::string			name;
		unsigned int		hp;
		Server				*server;
		bool				connected;

		static unsigned int	available_id;

		Player(void);
	public:
		// Constructors
		Player(int client_fd, std::string& name, unsigned int hp):
			client_fd(client_fd),
			hp(hp),
			id(available_id++),
			server(nullptr),
			connected(false)
		{
			trim_str(name);
			if (name.empty())
				throw PlayerInitiationException("Player name cannot be empty");
			this->name = name;
		}
		Player(const Player& player):
			client_fd(player.client_fd),
			id(player.id),
			name(player.name),
			hp(player.hp),
			server(player.server),
			connected(player.connected)
		{
		}
		~Player(void) = default;

		// Operators
		Player&	operator=(const Player& other)
		{
			if (this == &other)
				return (*this);
			client_fd = other.client_fd;
			id = other.id;
			name = other.name;
			hp = other.hp;
			server = other.server;
			connected = other.connected;
			return (*this);
		}

		// Getters and setters
		int				get_client_fd(void) const noexcept
		{
			return (client_fd);
		}

		unsigned int	get_id(void) const noexcept
		{
			return (id);
		}

		std::string		get_name(void) const noexcept
		{
			return (name);
		}

		unsigned int	get_hp(void) const noexcept
		{
			return (hp);
		}

		Server			*get_server(void) const noexcept
		{
			return (server);
		}

		bool			is_connected(void) const noexcept
		{
			return (connected);
		}

		void			set_client_fd(int client_fd) noexcept
		{
			this->client_fd = client_fd;
		}

		void			set_connected(bool connected) noexcept
		{
			this->connected = connected;
		}

		// Utils
		void	disconnect(void) noexcept
		{
			if (!connected)
				return ;
			connected = false;
			close(client_fd);
		}
};

unsigned int	Player::available_id = 1;

class Server
{
	private:
		int					sock_fd;
		sockaddr_in			address;
		std::list<Player>	player_list;
		bool				on;
		std::mutex			mtx;
	public:
		// Constructors
		Server(void)
		{
			int			sock;
			sockaddr_in	address;

			sock = socket(AF_INET, SOCK_STREAM, 0);
			if (sock == -1)
				throw ServerInitiationException("Socket initiation failed");
			address.sin_family = AF_INET;
			address.sin_addr.s_addr = INADDR_ANY;
			address.sin_port = htons(8080);
			if (bind(sock, (sockaddr *)&address, sizeof(address)) == -1)
				throw ServerInitiationException("Socket binding failed");
			if (listen(sock, MAX_PLAYERS) == -1)
				throw ServerInitiationException("Socket listening failed");
			this->sock_fd = sock;
			this->address = address;
			on = true;
			std::cout << "Server initiated" << std::endl;
		}

		Server(const Server& server) = delete;

		~Server(void)
		{
			close_server();
		}

		// Operators
		// Not needed

		// Getters and setters
		int							get_sock_fd(void) const noexcept
		{
			return (sock_fd);
		}

		sockaddr_in					get_address(void) const noexcept
		{
			return (address);
		}

		const std::list<Player>&	get_player_list(void) const noexcept
		{
			return (player_list);
		}

		bool						is_on(void) const noexcept
		{
			return (on);
		}

		// Utils
		void	close_server(void)
		{
			running = false;
			for (Player& player: player_list)
				player.disconnect();
			on = false;
			shutdown(sock_fd, SHUT_RDWR);
			close(sock_fd);
		}

		Player&	connect_user(std::string name, int client_fd)
		{
			std::lock_guard<std::mutex>	lock(mtx);
			for (Player& p: player_list)
			{
				if (p.get_name() == name)
				{
					if (p.is_connected())
						throw std::runtime_error("Name already in use\n");
					p.set_client_fd(client_fd);
					p.set_connected(true);
					return (p);
				}
			}
			player_list.push_back(Player(client_fd, name, 10));
			Player& p = player_list.back();
			p.set_connected(true);
			return (p);
		}
};

class ServerOwner
{
	private:
		std::string	name;
		Server&		server;
		std::string	password;

		ServerOwner(void);
		ServerOwner(const ServerOwner& server_owner);
	public:
		// Constructors
		ServerOwner(std::string name, Server& server):
			server(server),
			password("Hola")
		{
			if (name.empty())
				throw std::invalid_argument("Server owner name cannot be empty");
			this->name = name;
		}
		~ServerOwner(void) = default;

		// Operators
		// Not needed

		// Getters and setters
		std::string		get_name(void) const noexcept
		{
			return (name);
		}

		Server&			get_server(void) const noexcept
		{
			return (server);
		}

		// Utils
		void	close_server(void) const noexcept
		{
			std::string	answer;

			std::cout << "Introduce password: ";
			std::cin >> answer;
			if (answer == password)
				server.close_server();
			else
				std::cout << "Incorrect password" << std::endl;
		}
};

std::string	ask_name(int client_fd)
{
	const std::string	insert_name_msg = "Insert your name: ";
	std::string			result;
	ssize_t				bytes;
	char				buffer[MAX_NAME_LENGTH];


	if (send(client_fd, insert_name_msg.c_str(), insert_name_msg.size(), 0) == -1)
	{
		// std::cout << "Client " << client_fd << " unexpectedly disconnected" << std::endl;
		// close(client_fd);
		// return ("");
		throw std::runtime_error("Client " + std::to_string(client_fd) + " unexpectedly disconnted");
	}
	bytes = recv(client_fd, buffer, MAX_NAME_LENGTH, 0);
	if (bytes == 0)
		return ("");
	if (bytes == -1)
	{
		// std::cout << "Client " << client_fd << " unexpectedly disconnected" << std::endl;
		// close(client_fd);
		// return ("");
		throw std::runtime_error("Client " + std::to_string(client_fd) + " unexpectedly disconnted");
	}
	result = std::string(buffer, bytes);
	trim_str(result);
	return (result);
}

// Ask name
// Create player if it doesn't exist in the list
// Add it to the list in case it doesn't exist
// Start playing
void	client_thread(Server& server, int client_fd)
{
	const std::string	invalid_name_msg = "Name cannot be empty\n";
	std::string			player_name;
	std::string			welcome_msg;
	Player				*player;
	ssize_t				bytes;
	char				buffer[MAX_MSG_LENGTH];

	try
    {
        player = nullptr;
		while (!player)
		{
			player_name = ask_name(client_fd);
			if (player_name.empty())
			{
				if (send(client_fd, invalid_name_msg.c_str(), invalid_name_msg.size(), 0) == -1)
					throw std::runtime_error("Client " + std::to_string(client_fd) + " unexpectedly disconnted");
				continue;
			}
			try
			{
				player = &server.connect_user(player_name, client_fd);
			}
			catch (const std::runtime_error& e)
			{
				if (send(client_fd, e.what(), strlen(e.what()), 0) == -1)
					throw std::runtime_error("Client " + std::to_string(client_fd) + " unexpectedly disconnted");
			}
		}
		welcome_msg = "Welcome, " + player->get_name() + "\n";
		if (send(client_fd, welcome_msg.c_str(), welcome_msg.size(), 0) == -1)
			throw std::runtime_error("Player " + player->get_name() + " unexpectedly disconnted");
		while (true)
		{
			memset(buffer, 0, MAX_MSG_LENGTH);
			bytes = recv(player->get_client_fd(), buffer, MAX_MSG_LENGTH, 0);
			if (bytes == 0)
			{
				player->disconnect();
				break;
			}
			if (bytes == -1)
			{
				player->disconnect();
				break;
			}
			std::cout << player->get_name() << ": " << std::string(buffer, bytes) << std::endl;
		}
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        close(client_fd);
    }
}

void	monitor_thread(ServerOwner& owner)
{
	// Accept commands from stdin until 'quit'
	const Server&	server = owner.get_server();
	std::string		command;

	while (true)
	{
		std::cin >> command;
		if (command == "quit")
		{
			owner.close_server();
			if (!owner.get_server().is_on())
				break;	// Shutdown successfull
		}
		if (command == "show")
		{
			for (const Player& player: server.get_player_list())
			{
				std::cout << "Player " + player.get_name() + ": ";
				std::cout << std::to_string(player.get_client_fd());
				std::cout << " ";
				std::cout << player.is_connected();
				std::cout << std::endl;
			}
		}
		// TODO: Add commands
	}
}

int	main(void)
{
	Server		server;
	ServerOwner	owner("Juanpi", server);
	int			client_fd;

	std::thread	monitor(monitor_thread, std::ref(owner));
	while (running)
	{
		client_fd = accept(server.get_sock_fd(), nullptr, nullptr);
		if (client_fd == -1)
		{
			if (!running)
				break;
			throw std::runtime_error("Error while accepting client");
		}
		std::thread	client(client_thread, std::ref(server), client_fd);
		client.detach();
	}
	monitor.join();
}
