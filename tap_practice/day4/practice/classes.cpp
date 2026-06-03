#include <iostream>
#include <list>
#include <memory>	// Unique_ptr

class Quest
{
	public:
		std::string		description;
		bool			completed;
};

class Item
{
	public:
		std::string		name;
		std::string		description;
		void	use() const
		{
			std::cout << name << " was used" << std::endl;
		}
};

class Player
{
	public:
		std::string			name;
		unsigned int		hp;
		std::list<Item>		bag;
		std::list<Quest>	quests;
};

class NPC
{
	public:
		std::string		name;
		virtual void	interact() = 0;	// Abstract
};

class Enemy: public NPC
{
	public:
		void	interact() override
		{
			std::cout << "I´m an enemy" << std::endl;
		}
};

class QuestGiver: public NPC
{
	public:
		void	interact() override
		{
			std::cout << "I´m a quest-giver" << std::endl;
		}
};

class Room
{
	public:
		std::string			name;
		bool				checkpoint;
		std::list<Player>	players;
		std::list<Item>		items;
		std::list<NPC>		npcs;	// CUIDADO AQUÍ, como es abstracta no funcionaría
		std::list<NPC*>		npcs_ptr;	// Así habría que liberarlos manualmente
		std::list<std::unique_ptr<NPC>>	npcs_unique_ptr;	// Así se libera todo automaticamente
};
