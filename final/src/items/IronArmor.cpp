#include "items/IronArmor.hpp"

const std::string	IronArmor::NAME = "Iron Armor";
const std::string	IronArmor::DESCRIPTION = "Reduces incoming damage";

void	IronArmor::special_use(void) noexcept
{
	// TODO: Logic...
}

// Constructors ---------------------------------------------------------------

IronArmor::IronArmor(void):
	Armor(NAME, DESCRIPTION, REDUCED_DAMAGE)
{
}

IronArmor::IronArmor(const IronArmor& iron_armor):
	Armor(iron_armor.NAME, iron_armor.DESCRIPTION, iron_armor.REDUCED_DAMAGE)
{
}
