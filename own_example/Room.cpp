#include "Room.hpp"

// Constructors
Room::Room(const std::string& name, const std::string& description):
	name(name),
	description(description)
{
}

Room::Room(const Room& room):
	name(room.name),
	description(room.description)
{
}

// Operators
Room&	Room::operator=(const Room& other)
{
	if (this == &other)
		return (*this);
	name = other.name;
	description = other.description;
	return (*this);
}

// Getters and setters
const std::string&			Room::get_name(void) const
{
	return (name);
}

const std::string&			Room::get_description(void) const
{
	return (description);
}

const std::list<Item*>&		Room::get_items_in_room(void) const
{
	return (items_in_room);
}

const std::list<NPC*>&		Room::get_npcs_in_room(void) const
{
	return (npcs_in_room);
}

const std::list<Player*>&	Room::get_players_in_room(void) const
{
	return (players_in_room);
}

// Utils
// TODO: Add players, ...
