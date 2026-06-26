#pragma once

#include "Fighter.hpp"
#include "Merchant.hpp"
#include "Enemy.hpp"

// Server stuff is managed in PlayerConnection class
class Player final: public Fighter
{
	private:
		// Zone			*location;
		// Weapon			*weapon;
		unsigned int		gold;
		std::list<Enemy*>	beaten_enemies;

	public:
		// Constructors
		Player(const std::string& name);
		Player(const Player& player) = delete;
		~Player(void) = default;

		// Operators
		Player&	operator=(const Player& other) = delete;

		// Getters and setters
		unsigned int				get_gold(void) const noexcept;
		std::list<Enemy*>&			get_beaten_enemies(void) noexcept;
		const std::list<Enemy*>&	get_beaten_enemies(void) const noexcept;

		// Utils --------------------------------------------------------------
		// Items
		void			buy_item(const Merchant& merchant, Item *item);

		// Location
		void			move(void);

		// Fight
		void			attack(Fighter *target) noexcept override;

		// Other
		virtual void	interact(Character& character) override;
};
