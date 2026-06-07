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

int	main(void)
{
	Player	player1;
	Player	player2(20, "Pepe");
	Enemy	enemy1(15, "Marcos");

	func(&player1);
	// func(Player());
	std::cout << std::endl;

	// Character	*characters = new Player[5];	// NO, use lists instead
	// delete[] characters;
	std::list<Character *>	character_list;
	character_list.push_back(&player1);
	character_list.push_back(&player2);
	character_list.push_back(&enemy1);

	for (Character *character: character_list)
	{
		std::cout << character->get_name() << std::endl;
	}
	std::cout << std::endl;

	Character	*c1 = new Player(15, "Pablo");
	Character	*c2 = new Enemy(30, "Maria");
	std::list<Character *>	ptr_characters_list;
	ptr_characters_list.push_back(c1);
	ptr_characters_list.push_back(c2);
	for (Character *character: ptr_characters_list)
	{
		std::cout << character->get_name() << std::endl;
		delete (character);
	}
	std::cout << std::endl;
	
	Player	p1(20, "Diego");
	Player	p2(30, "Mateo");
	std::cout << std::endl;
	std::list<Player>	player_list;
	player_list.push_back(p1);	// These are copies too
	player_list.push_back(p2);
	std::cout << std::endl;
	for (Player player: player_list)	// Every iteration is a copy (not with reference &)
	{
		std::cout << player.get_name() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
