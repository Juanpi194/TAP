#pragma once
#include <string>
#include <list>

#include "Quest.hpp"
#include "Item.hpp"

class Room;

class Player
{
	private:
		std::string			name;
		std::list<Quest>	quest_list;
		std::list<Item*>		item_list;
		int					client_fd;
		unsigned int		id;
		Room*				current_room;
	public:
		// Constructors
		Player(const std::string& name, int client_fd);	// Lists will start being empty, room will point to nullptr
		Player(const Player& player);
		~Player() = default;

		// Operators
		Player&	operator=(const Player& other);

		// Getters and setters
		const std::string&		get_name(void) const;
		const std::list<Quest>&	get_quest_list(void) const;
		const std::list<Item>&	get_item_list(void) const;
		int						get_client_fd(void) const;
		unsigned int			get_id(void) const;
		Room*					get_current_room(void) const;
		void					set_current_room(Room* room);

		// Utils
		void	add_quest(const Quest& quest);
		void	remove_quest(const Quest& quest);
		void	add_item(const Item& item);
		void	remove_item(const Item& item);
};
