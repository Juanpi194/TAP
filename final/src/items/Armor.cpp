#include "items/Armor.hpp"

// Constructors ---------------------------------------------------------------

Armor::Armor(const std::string& name, const std::string& description, unsigned int reduced_damage):
	Gear(name, description),
	reduced_damage(reduced_damage)
{
}

Armor::Armor(const Armor& armor):
	Gear(armor.get_name(), armor.get_description()),
	reduced_damage(armor.reduced_damage)
{
}

// Getters and setters --------------------------------------------------------

unsigned int	Armor::get_reduced_damage(void) const noexcept
{
	return (reduced_damage);
}

// Utils ----------------------------------------------------------------------

void	Armor::use(void) noexcept
{
	// TODO: Logic...
	special_use();
}
