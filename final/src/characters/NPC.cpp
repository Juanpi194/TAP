#include "characters/NPC.hpp"

#include <iostream>

#include "utils.hpp"

// Constructors ---------------------------------------------------------------

NPC::NPC(const std::string& name, const std::string& description):
	Character(name),
	description(description)
{
	std::string	temp = description;

	trim_str(temp);
	if (temp.empty())
		throw std::invalid_argument("NPC description cannot be empty.");
}

NPC::NPC(const NPC& npc):
	Character(npc.get_name()),
	description(npc.description)
{
	this->current_room = npc.current_room;
}

// Getters and setters --------------------------------------------------------

std::string	NPC::get_description(void) const noexcept
{
	return (description);
}

// Utils ----------------------------------------------------------------------

// TODO
