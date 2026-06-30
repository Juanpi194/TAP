#include "characters/Character.hpp"

#include <iostream>

#include "utils.hpp"

Character::Character(const std::string& name):
	name(name),
	current_room(nullptr)
{
	std::string	temp = name;

	trim_str(temp);
	if (temp.empty())
		throw std::invalid_argument("Character name cannot be empty");
}

Character::Character(const Character& character):
	name(character.name),
	current_room(character.current_room)
	// TODO: Item list starts empty right now
{
	log("Character '" + character.name + "' was copied", LogLevel::DEBUG);
}

Character&	Character::operator=(const Character& other)
{
	if (this == &other)
		return (*this);
	name = other.name;
	current_room = other.current_room;
	// TODO: Item list starts empty right now
	return (*this);
}

std::string				Character::get_name(void) const noexcept
{
	return (name);
}

const std::list<Item*>&	Character::get_item_list(void) const noexcept
{
	return (item_list);
}

Room					*Character::get_current_room(void) const noexcept
{
	return (current_room);
}

void	Character::set_name(const std::string& name)
{
	std::string	temp = name;

	trim_str(temp);
	if (temp.empty())
	{
		log("Tried to set empty name. Change was not done.", LogLevel::WARNING);
		return ;
	}
	this->name = name;
}

void	Character::obtain_item(Item *item)
{
	// TODO
}

void	Character::drop_item(Item *item)
{
	// TODO
}
