#include <iostream>
#include <string>
#include <cstring>

class Character
{
	private:
		std::string	name;
	public:
		Character(const std::string& name)
		{
			this->name = name;
			std::cout << "Character " << name << " initiated" << std::endl;
		}

		~Character(void)
		{
			std::cout << "Character " << name << " destroyed" << std::endl;
		}

		std::string	get_name(void) const noexcept
		{
			return (name);
		}

		virtual void	fight(void) = 0;
};

class Player: public Character
{
	private:
		unsigned int	hp;
	public:
		Player(unsigned int hp, const std::string& name):
			Character(name),
			hp(hp)
		{
			std::cout << "Player " << name << " created" << std::endl;
		}
		
		Player(const Player& player):
			Character(player.get_name()),
			hp(player.hp)
		{
			std::cout << "Player " << this->get_name() << " got copied" << std::endl;
		}

		~Player(void)
		{
			std::cout << "Player " << this->get_name() << " destroyed" << std::endl;
		}

		// Operators
		// Player&	operator=(const Player& other)
		// {
		// 	std::cout << "Person operator= called (" << other.name << ")" << std::endl;
		// 	if (this == &other)
		// 		return (*this);
		// 	this->hp = other.hp;
		// 	this->name = other.name;
		// 	return (*this);
		// }
		bool	operator==(const Player& other)
		{
			if (this->hp == other.hp)
				return (true);
			return (false);
		}

		// Getters and setters
		unsigned int	get_hp(void) const
		{
			return (hp);
		}

		void	fight(void) override
		{
			std::cout << this->get_name() << " is fighting as a player" << std::endl;
		}
		// Utils
		// virtual void	greet() const
		// {
		// 	std::cout << "Hello, i am " << name << ", and i am " << hp << " years old" << std::endl;
 		// }
};


int	main(void)
{
	// Character	character("Rocio");
	Player	player(10, "Juanpi");

	std::cout << player.get_name() << std::endl;
	player.fight();
	return (0);
}
