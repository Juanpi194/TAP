#include "Character.hpp"

Character::Character(const std::string& name):
	name(name)
{
	std::cout << name << " initiated" << std::endl;
}

std::string	Character::get_name(void) const noexcept
{
	return (name);
}
