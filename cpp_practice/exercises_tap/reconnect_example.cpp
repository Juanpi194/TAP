#include <iostream>
#include <string>
#include <list>


class Player
{
	private:
		std::string		name;
		unsigned int	hp;
		std::string		room;
		bool			connected;
		Player(void);	// So it cannot be used
	public:
		// Constructors
		Player(const std::string& name, unsigned int hp, const std::string& room):
			name(name),
			hp(hp),
			room(room),
			connected(false)
		{
		}
		Player(const Player& player):
			name(player.name),
			hp(player.hp),
			room(player.room),
			connected(player.connected)
		{
		}
		~Player(void) = default;

		// Operators
		Player&	operator=(const Player& other)
		{
			if (this == &other)
				return (*this);
			name = other.name;
			hp = other.hp;
			room = other.room;
			connected = other.connected;
			return (*this);
		}

		// Getters and setters
		std::string		get_name(void) const noexcept	// Copy in purpose
		{
			return (name);
		}

		unsigned int	get_hp(void) const noexcept
		{
			return (hp);
		}

		std::string		get_room(void) const noexcept	// Copy in purpose
		{
			return (room);
		}

		bool			is_connected(void) const noexcept
		{
			return (connected);
		}

		void			set_connected(bool connected) noexcept
		{
			this->connected = connected;
		}

		// Utils
		// TODO
};

void	reconnect(std::list<Player>& player_list, const std::string& player_name)
{
	for (Player& player: player_list)
	{
		if (player.get_name() == player_name)
		{
			if (player.is_connected())
				std::cout << "Player '" << player.get_name() << "' is already connected" << std::endl;
			else
			{
				player.set_connected(true);
				std::cout << "Player '" << player.get_name() << "' connected successfully" << std::endl;
			}
			return ;
		}
	}
	std::cout << "Player '" << player_name << "' is not in the list" << std::endl;
	std::cout << "Adding it to the list and connecting it..." << std::endl;
	player_list.push_back(Player(player_name, 20, "RoomX"));
	player_list.back().set_connected(true);
}

int	main(void)
{
	std::list<Player>	player_list = {Player("Juanpi", 20, "Room1"),
									   Player("Rocio", 20, "Room2"),
									   Player("Chrystian", 20, "Room3")};

	reconnect(player_list, "aaa");
	reconnect(player_list, "Rocio");
	for (Player& player: player_list)
	{
		std::cout << "Name: " << player.get_name() << std::endl;;
		std::cout << "Connected: " << player.is_connected() << std::endl;
		std::cout << "---" << std::endl;
	}
	return (0);
}
