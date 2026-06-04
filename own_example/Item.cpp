#include "Item.hpp"

// Constructors
Item::Item(const std::string& name, const std::string& description):
	name(name),
	description(description)
{
}

Item::Item(const Item& item):
	name(item.name),
	description(item.description)
{
}


// Operators
Item&	Item::operator=(const Item& other)
{
	if (this == &other)
		return (*this);
	name = other.name;
	description = other.description;
	return (*this);
}

// Getters and setters
const std::string&	Item::get_name(void) const
{
	return (name);
}

const std::string&	Item::get_description(void) const
{
	return (description);
}

// Utils
// TODO
