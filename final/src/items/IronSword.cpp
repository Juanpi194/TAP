#include "items/IronSword.hpp"

const std::string	IronSword::NAME = "Iron Sword";
const std::string	IronSword::DESCRIPTION = "Applies extra damage";

void	IronSword::special_use(void) noexcept
{
	// TODO: Logic...
}

// Constructors ---------------------------------------------------------------

IronSword::IronSword(void):
	Weapon(NAME, DESCRIPTION, EXTRA_DAMAGE)
{
}

IronSword::IronSword(const IronSword& sword):
	Weapon(sword.NAME, sword.DESCRIPTION, sword.EXTRA_DAMAGE)
{
}
