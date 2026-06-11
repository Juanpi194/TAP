#include <iostream>
#include <string>


class Player
{
	private:
		std::string		name;
		unsigned int	hp;
		std::string		room;
		Player(void);	// So it cannot be used
	public:
		// Constructors
		Player(const std::string& name, unsigned int hp, const std::string& room):
			name(name),
			hp(hp),
			room(room)
		{
		}
		Player(const Player& player):
			name(player.name),
			hp(player.hp),
			room(player.room)
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

		// Utils
		// TODO
};

std::string	player_to_json(const Player& player)
{
	std::string	result;

	result += "{";
	result += "\"name\": \"" + player.get_name() + "\", ";
	result += "\"hp\": " + std::to_string(player.get_hp()) + ", ";	// Numbers not between quotes
	result += "\"room\": \"" + player.get_room() + "\"";
	result += "}";
	return (result);
}

int	main(void)
{
	Player		player("Yeipi", 20, "Cluster 8");
	std::string	result;

	result = player_to_json(player);
	std::cout << result << std::endl;
	return (0);
}
