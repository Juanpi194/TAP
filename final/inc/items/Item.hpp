#pragma once
#include <string>

class Item
{
	private:
		const std::string	name;
		const std::string	description;
	public:
		// Constructors
		Item(const std::string& name, const std::string& description);
		Item(const Item& item);
		virtual ~Item(void) = default;

		// Operators
		Item&	operator=(const Item& other) = delete;

		// Getters and setters
		std::string	get_name(void) const noexcept;
		std::string	get_description(void) const noexcept;

		// Utils
		virtual void	use(void) noexcept = 0;
};
