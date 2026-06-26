#include "World.hpp"

// Constructors
World::World(const std::string& name):
	name(name)
{
}

World::World(const World& world):
	name(world.name)
{
	// TODO: copy room_list, ...
}

// Operators
World&	World::operator=(const World& other)
{
	if (this == &other)
        return (*this);
    // TODO: copy room_list, ...
    return (*this);
}

// Getters and setters
const std::string&			World::get_name(void) const
{
	return (name);
}

// const std::list<Player>&	get_player_list(void) const;
const std::list<Room*>&		World::get_room_list(void) const
{
	return (room_list);
}

// Utils
// TODO: qol functions...
