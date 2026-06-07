#include <list>
#include <string>
#include <iostream>

class Character
{
	protected:
		unsigned int	hp;
		std::string		name;
	public:
		// Constructors
		Character(void):
			hp(10),
			name("Juanpi")
		{
			std::cout << "Character (Default constructor) " << name << " created" << std::endl;
		}
		Character(unsigned int hp, const std::string& name):
			hp(hp),
			name(name)
		{
			std::cout << "Character (Normal constructor) " << name << " created" << std::endl;
		}
		Character(const Character& character):
			hp(character.hp),
			name(character.name)
		{
			std::cout << "Character (Copy constructor) " << name << " created" << std::endl;
		}
		~Character(void)
		{
			std::cout << "Character " << name << " destroyed" << std::endl;
		}

		// Operators
		Character& operator=(const Character& other)
		{
			if (this == &other)
				return (*this);
			hp = other.hp;
			name = other.name;
		}

		// Getters and setters
		unsigned int			get_hp(void) const
		{
			return (hp);
		}

		const std::string&		get_name(void) const
		{
			return (name);
		}

		// Utils
		// TODO
};

class Player: public Character
{
	private:
		unsigned int	gold;
	public:
		// Constructors
		Player(void):
			Character(),
			gold(0)
		{
			std::cout << "Player (Default constructor) " << name << " created" << std::endl;
		}
		Player(unsigned int hp, const std::string& name):
			Character(hp, name),
			gold(0)
		{
			std::cout << "Player (Normal constructor) " << name << " created" << std::endl;
		}
		Player(const Player& player):
			Character(player.hp, player.name),
			gold(player.gold)
		{
			std::cout << "Player (Copy constructor) " << name << " created" << std::endl;
		}

		// Operators
		Player& operator=(const Player& other)
		{
			if (this == &other)
				return (*this);
			hp = other.hp;
			name = other.name;
			gold = other.gold;
		}

		// Getters and setters
		unsigned int	get_gold(void) const
		{
			return (gold);
		}

		// Utils
		// TODO
};

class Enemy: public Character
{

};

void	func(Character character)
{
	std::cout << "Character's name: " << character.get_name() << std::endl;
}

int	main(void)
{
	Player player;

	func(player);
	// func(Player());
	std::cout << std::endl;

	Character	*characters = new Character[5];
	delete[] characters;
	std::cout << std::endl;

	return (0);
}
