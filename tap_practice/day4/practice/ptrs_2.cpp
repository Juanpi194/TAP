#include <iostream>
#include <list>

class Item
{
	public:
		std::string	name;
		std::string	description;

		Item(std::string&& name, std::string&& description)
		{
			this->name = std::move(name);
			this->description = std::move(description);
		}
		~Item()
		{
			std::cout << "Destroying " << name << std::endl;
		}
};

class Player
{
	public:
		std::string		name;
		unsigned int	hp;
		std::list<Item>	bag;

		Player(std::string&& name, unsigned int hp)
		{
			this->name = name;	// Habría que hacer move...
			this->hp = hp;
			std::cout << "Player " << this->name << " created" << std::endl;
		}
		~Player()
		{
			std::cout << "Player " << this->name << " destroyed" << std::endl;
		}

		void	give_item(Item&& item)	// Pedimos un rvalue, PERO en la función ya es un lvalue, hay que volver a moverlo
		{
			std::string	item_name = item.name;
			bag.push_back(std::move(item));
			std::cout << "Player " << name << " received " << item_name << std::endl;
		}
};

class Room
{
	public:
		std::string			name;
		std::list<Player>	player_list;

		Room(std::string&& name)
		{
			this->name = name;
		}
		~Room()
		{
			std::cout << "Destroying room " << name << std::endl;
		}

		void	add_player(Player&& player)
		{
			std::string	player_name = player.name;	// Como lo vamos a mover, perderemos su acceso
			player_list.push_back(std::move(player));
			std::cout << "Player " << player_name << " added to " << name << std::endl;
		}
};

int	main(void)
{
	Player	p1("Juanpi", 10);
	Player	p2("Coco", 10);
	Item	item1("Potion", "Heals");
	Room	room("Entrance");

	p1.give_item(Item("Sword", "Increases power"));	// &&
	p1.give_item(std::move(item1));	// Moving & to a &&
	room.add_player(std::move(p1));
	// Until now, no leaks ----------------------------------------------------

	Player	*p3;
	p3 = new Player("Nublax", 10);	// Allocates memory
	delete (p3);	// Frees memory (calling the destructor)
	p3 = nullptr;	// Buena práctica
	return (0);
}
