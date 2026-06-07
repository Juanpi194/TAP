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
		virtual ~Character(void)
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
			return (*this);
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
		virtual void	interact(void) = 0;
};

class Player: public Character
{
	private:
		unsigned int	gold;
		unsigned int	level;
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
			Character(player),	// No idea
			gold(player.gold)
		{
			std::cout << "Player (Copy constructor) " << name << " created" << std::endl;
		}
		~Player(void)
		{
		}

		// Operators
		Player& operator=(const Player& other)
		{
			if (this == &other)
				return (*this);
			hp = other.hp;
			name = other.name;
			gold = other.gold;
			return (*this);
		}

		// Getters and setters
		unsigned int	get_gold(void) const
		{
			return (gold);
		}

		unsigned int	get_level(void) const
		{
			return (level);
		}

		// Utils
		// TODO
		void	interact(void) override
		{
			std::cout << "Hello, i'm "<< name << " and i'm a player" << std::endl;
		}
};

class Enemy: public Character
{
	private:
		unsigned int	exp;
	public:
		// Constructors
		Enemy(void):
			Character(),
			exp(10)
		{
			std::cout << "Enemy (Default constructor) " << name << " created" << std::endl;
		}
		Enemy(unsigned int hp, const std::string& name):
			Character(hp, name),
			exp(10)
		{
			std::cout << "Enemy (Normal constructor) " << name << " created" << std::endl;
		}
		Enemy(const Enemy& enemy):
			Character(enemy),
			exp(enemy.exp)
		{
			std::cout << "Enemy (Copy constructor) " << name << " created" << std::endl;
		}
		~Enemy(void)
		{
		}

		// Operators
		Enemy&	operator=(const Enemy& other)
		{
			if (this == &other)
				return (*this);
			hp = other.hp;
			name = other.name;
			exp = other.exp;
			return (*this);
		}

		// Getters and setters
		unsigned int	get_exp(void)
		{
			return (exp);
		}

		// Utils
		// TODO
		void	interact(void) override
		{
			std::cout << "Hello, i'm "<< name << " and i'm an emey" << std::endl;
		}
};

void	func(Character *character)
{
	std::cout << "Character's name: " << character->get_name() << std::endl;
}

Player	create_player(unsigned int hp, std::string&& name)
{
	Player	player(hp, name);

	return (player);
}

Player&	create_static_player(unsigned int hp, std::string&& name)
{
	static Player	player(hp, name);

	return (player);
}

int	main(void)
{
	// Player	player1;
	// Player	player2(20, "Pepe");
	// Enemy	enemy1(15, "Marcos");

	Player	p = create_player(10, "Jaime");
	std::cout << p.get_name() << std::endl;
	std::cout << std::endl;

	Player&	static_p = create_static_player(20, "Pedro");	// Without &, another copy would be created
	std::cout << static_p.get_name() << std::endl;
	std::cout << std::endl;
	return (0);
}
