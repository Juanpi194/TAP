#include "items/Gear.hpp"

// Constructors ---------------------------------------------------------------

Gear::Gear(const std::string& name, const std::string& description):
	Item(name, description)
{
}

Gear::Gear(const Gear& gear):
	Item(gear.get_name(), gear.get_description())
{
}
