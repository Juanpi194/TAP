#pragma once
#include <map>

#include "characters/NPC.hpp"

class Item;

constexpr unsigned int	MAX_ITEM_PRICE = 2000;

class Merchant final: public NPC
{
	private:
		const std::map<Item*, unsigned int>	items_to_sell;	// Item and price
	public:
		// Constructors
		Merchant(const std::string& name, const std::string& description, const std::map<Item*, unsigned int>& items_to_sell);
		Merchant(const Merchant& merchant);
		~Merchant(void) = default;

		// Operators
		Merchant&	operator=(const Merchant& other) = delete;

		// Getters and setters
		const std::map<Item*, unsigned int>	get_items_to_sell(void) const noexcept;

		// Utils
		void	on_interact(Player& player) override;
};
