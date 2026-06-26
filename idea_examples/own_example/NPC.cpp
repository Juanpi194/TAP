#include "NPC.hpp"

// Constructors
NPC::NPC(const std::string& name, const std::string& description):
	name(name),
	description(description)
{
}

NPC::NPC(const NPC& npc):
	name(npc.name),
	description(npc.description)
{
}

// Operators
NPC&	NPC::operator=(const NPC& other)
{
	if (this == &other)
		return (*this);
	name = other.name;
	description = other.description;
	return (*this);
}

// Getters and setters
const std::string&	NPC::get_name(void) const
{
	return (name);
}

const std::string&	NPC::get_description(void) const
{
	return (description);
}

// Utils
// TODO
