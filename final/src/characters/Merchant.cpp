#include "characters/Merchant.hpp"

// Constructors ---------------------------------------------------------------

Merchant::Merchant(const std::string& name, const std::string& description, const std::map<Item*, unsigned int>& items_to_sell):
	Character(name),
	NPC(name, description),
	items_to_sell(items_to_sell)
{
	// TODO: Check if there is any nullptr in the given item list.
}

Merchant::Merchant(const Merchant& merchant):
	Character(merchant.get_name()),
	NPC(merchant.get_name(), merchant.get_description()),
	items_to_sell(merchant.items_to_sell)
{
	this->current_room = merchant.current_room;
}

Merchant::~Merchant(void)
{
	// TODO: Free all items from inventory.
}

// Getters and setters --------------------------------------------------------

const std::map<Item*, unsigned int>	Merchant::get_items_to_sell(void) const noexcept
{
	return (items_to_sell);
}

// Utils ----------------------------------------------------------------------

void	Merchant::on_interact(Player& player)
{
	// TODO: Logic ...
}
