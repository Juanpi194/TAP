#include <iostream>
#include <string>
#include <list>
#include <map>
// #include <functional>

class Fighter
{
	protected:
		std::string		name;
		unsigned int	hp;
		unsigned int	attack;
	public:
		// Constructors
		Fighter(const std::string& name, unsigned int hp, unsigned int attack):
			name(name),
			hp(hp),
			attack(attack)
		{
		}
		Fighter(const Fighter& fighter):
			name(fighter.name),
			hp(fighter.hp),
			attack(fighter.attack)
		{
		}
		virtual ~Fighter(void) noexcept = default;

		// Operators
		Fighter&	operator=(const Fighter& other) noexcept
		{
			if (this == &other)
				return (*this);
			name = other.name;
			hp = other.hp;
			attack = other.attack;
			return (*this);
		}

		// Getters and setters
		std::string		get_name(void) const noexcept	// Returns a copy
		{
			return (name);
		}

		unsigned int	get_hp(void) const noexcept
		{
			return (hp);
		}

		unsigned int	get_attack(void) const noexcept
		{
			return (attack);
		}

		void	set_name(const std::string& name)
		{
			if (!name.empty())
				this->name = name;
		}

		// Utils
		// TODO
		virtual void	fight(Fighter& rival) = 0;
};

class Player final: public Fighter
{
	private:
		unsigned int	level;
		unsigned int	gold;
		// std::list<Item*>	item_list;	// Not necessary now
	public:
		// Constructors
		Player(const std::string& name, unsigned int hp, unsigned int attack):
			Fighter(name, hp, attack),
			level(1),
			gold(0)
		{
		}
		Player(const Player& player):
			Fighter(player),
			level(player.level),
			gold(player.gold)
		{
		}
		~Player(void) = default;

		// Operators
		Player&	operator=(const Player& other) noexcept
		{
			if (this == &other)
				return (*this);
			// name = other.name;
			// hp = other.hp;
			// attack = other.attack;
			Fighter::operator=(other);	// This is better than the commented above
			level = other.level;
			gold = other.gold;
			return (*this);
		}

		// Getters and setters
		unsigned int	get_level(void) const noexcept
		{
			return (level);
		}

		unsigned int	get_gold(void) const noexcept
		{
			return (gold);
		}

		// Utils
		// TODO
		void	fight(Fighter& rival) override
		{
			std::cout << name << " fights " << rival.get_name() << std::endl;
			// TODO: ...
		}
};

class Enemy final: public Fighter
{
	private:
		// Add attributes ...
	public:
		// Constructors
		Enemy(const std::string& name, unsigned int hp, unsigned int attack):
			Fighter(name, hp, attack)
		{
		}
		Enemy(const Enemy& enemy):
			Fighter(enemy)
		{
		}
		~Enemy(void) = default;

		// Operators
		Enemy&	operator=(const Enemy& other) noexcept
		{
			if (this == &other)
				return (*this);
			// name = other.name;
			// hp = other.hp;
			// attack = other.attack;
			Fighter::operator=(other);
			return (*this);
		}

		// Getters and setters
		// TODO

		// Utils
		// TODO
		void	fight(Fighter& rival) override
		{
			std::cout << name << " fights " << rival.get_name() << std::endl;
			// TODO: ...
		}
};

enum class Command
{
	SEARCH,
	ATTACK,
	STATUS,
	HELP,
	QUIT,
	UNKNOWN
};

Command	parse_command(const std::string& cmd)
{
	if (cmd == "search")
		return Command::SEARCH;
	// TODO
	if (cmd == "quit")
		return Command::QUIT;
	else
		return Command::UNKNOWN;
}

Enemy	search(unsigned int player_level)
{
	if (player_level < 10)
		return (Enemy("Goblin", 5, 2));
	if (player_level < 20)
		return (Enemy("Wizard", 15, 10));
	// TODO: ...
	else
		return (Enemy("Golem", 45, 6));
}

int	main(void)
{
	Player		p("Juanpi", 20, 8);
	Enemy		*e;
	std::string	line;
	bool		running;
	// std::map<std::string, void(*)>	commands; 

	// Receive command and execute
	e = nullptr;
	running = true;
	while (running)
	{
		std::getline(std::cin, line);
		switch (parse_command(line))
		{
			case Command::SEARCH:
				e = new Enemy(search(p.get_level()));
				p.fight(*e);
				delete (e);
				break;
			case Command::QUIT:
				running = false;
				break;
			default:
				std::cout << "Unknown command" << std::endl;
				break;
		}
	}
	return (0);
}
