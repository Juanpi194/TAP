#pragma once
#include <string>
#include <list>

#include "Item.hpp"

class Room;

class Character
{
	private:
		std::string			name;
		std::list<Item*>	item_list;
		Room				*current_room;
	public:
		// Constructors
		Character(const std::string& name);
		Character(const Character& character);
		virtual ~Character(void) = default;

		// Operators
		Character&	operator=(const Character& character);

		// Getters and setters
		std::string				get_name(void) const noexcept;
		const std::list<Item*>&	get_item_list(void) const noexcept;
		Room					*get_current_room(void) const noexcept;

		void					set_name(const std::string& name);

		// Utils
		void			obtain_item(Item *item);
		void			drop_item(Item *item);
		virtual void	interact(Character& character) = 0;
};
