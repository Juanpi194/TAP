#pragma once
#include <string>

class Item
{
	private:
		std::string	name;
		std::string	description;
	public:
		// Constructors
		Item(const std::string& name, const std::string& description);
		Item(const Item& item);
		virtual ~Item() = default;	// Default behavior

		// Operators
		Item&	operator=(const Item& other);

		// Getters and setters
		const std::string&	get_name(void) const;
		const std::string&	get_description(void) const;

		// Utils
		virtual void	use(void) = 0;
};
