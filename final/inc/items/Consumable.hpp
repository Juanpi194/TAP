#pragma once

#include "items/Item.hpp"

class Consumable: public Item
{
	private:
		// TODO
	public:
		// Constructors
		Consumable(const std::string& name, const std::string& description);
		Consumable(const Consumable& consumable);
		~Consumable(void) = default;

		// Operators
		Consumable&	operator=(const Consumable& other) = delete;

		// Getters and setters
		// TODO

		// Utils
		void	use(void) noexcept override;
};
