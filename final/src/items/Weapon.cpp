#include "items/Weapon.hpp"

// Constructors ---------------------------------------------------------------

Weapon::Weapon(const std::string& name, const std::string& description, unsigned int extra_damage):
	Gear(name, description),
	extra_damage(extra_damage)
{
}

Weapon::Weapon(const Weapon& weapon):
	Gear(weapon.get_name(), weapon.get_description()),
	extra_damage(weapon.extra_damage)
{
}

// Getters and setters --------------------------------------------------------

unsigned int	Weapon::get_extra_damage(void) const noexcept
{
	return (extra_damage);
}

// Utils ----------------------------------------------------------------------

void	Weapon::use(void) noexcept
{
	// TODO: Logic...
	special_use();
}
