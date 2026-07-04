#include "items/Item.hpp"

#include <iostream>

#include "utils.hpp"

bool	Item::validate_arguments(const std::string& name, const std::string& description)
{
	std::string	name_temp;
	std::string	desc_temp;

	// NAME
	name_temp = name;
	trim_str(name_temp);
	if (name_temp.empty())
		return (log("Item name cannot be empty.", LogLevel::ERROR), false);
	if (TITLE_NAME && !is_title(name_temp))
		return (log("Item name is not a title.", LogLevel::ERROR), false);
	if (name_temp.size() > MAX_NAME_LENGTH)
		return (log("Item name is too long (MAX CHARACTERS: " + std::to_string(MAX_NAME_LENGTH) + ").", LogLevel::ERROR), false);
	if (name_temp.size() < MIN_NAME_LENGTH)
		return (log("Item name is too short (MIN CHARACTERS: " + std::to_string(MIN_NAME_LENGTH) + ").", LogLevel::ERROR), false);

	// DESCRIPTION
	desc_temp = description;
	trim_str(desc_temp);
	if (desc_temp.empty())
		return (log("Description cannot be empty.", LogLevel::ERROR), false);
	if (desc_temp.size() > MAX_DESCRIPTION_LENGTH)
		return (log("Item description is too long (MAX CHARACTERS: " + std::to_string(MAX_DESCRIPTION_LENGTH) + ").", LogLevel::ERROR), false);
	if (desc_temp.size() < MIN_DESCRIPTION_LENGTH)
		return (log("Item description is too short (MIN CHARACTERS: " + std::to_string(MIN_DESCRIPTION_LENGTH) + ").", LogLevel::ERROR), false);
	return (true);
}

// Constructors ---------------------------------------------------------------

Item::Item(const std::string& name, const std::string& description):
	name(name),
	description(description)
{
	if (!validate_arguments(name, description))
		throw std::invalid_argument("Item validation failed.");
}

Item::Item(const Item& item):
	name(item.name),
	description(item.description)
{
}

// Getters and setters --------------------------------------------------------

std::string	Item::get_name(void) const noexcept
{
	return (name);
}

std::string	Item::get_description(void) const noexcept
{
	return (description);
}
