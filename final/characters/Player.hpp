#pragma once

#include "Fighter.hpp"
#include "Merchant.hpp"

// Server stuff is managed in PlayerConnection class
class Player final: public Fighter
{
	private:
		// Zone			*location;
		// Weapon			*weapon;
		unsigned int	gold;

	public:
		// Constructors
		Player(const std::string& name);
		Player(const Player& player) = delete;
		~Player(void) = default;

		// Operators
		Player&	operator=(const Player& other) = delete;

		// Getters and setters
		unsigned int	get_gold(void) const noexcept;

		// Utils --------------------------------------------------------------
		// Items
		void	buy_item(const Merchant& merchant, Item *item);

		// Location
		void	move(void);

		// Fight
		void	attack(Fighter *target) noexcept override;
};
