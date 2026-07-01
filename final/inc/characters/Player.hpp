#pragma once

#include "characters/Fighter.hpp"
#include "quests/Quest.hpp"

class Room;
class Enemy;
class Merchant;

// Server stuff is managed in PlayerConnection class
class Player final: public Fighter
{
	private:
		Room				*current_location;
		// Weapon			*weapon;
		unsigned int		gold;
		std::list<Enemy*>	beaten_enemies;
		std::list<Quest>	quest_list;
	public:
		// Constructors -------------------------------------------------------

		Player(const std::string& name);
		Player(const Player& player) = delete;
		~Player(void) = default;

		// Operators ----------------------------------------------------------

		Player&	operator=(const Player& other) = delete;

		// Getters and setters ------------------------------------------------

		Room						*get_current_location(void) const noexcept;
		unsigned int				get_gold(void) const noexcept;
		std::list<Enemy*>&			get_beaten_enemies(void) noexcept;
		const std::list<Enemy*>&	get_beaten_enemies(void) const noexcept;
		std::list<Quest>&			get_quest_list(void) noexcept;
		const std::list<Quest>&		get_quest_list(void) const noexcept;

		// Utils --------------------------------------------------------------

		// Items
		void			buy_item(const Merchant& merchant, Item *item);

		// Location
		void			move(void);

		// Fight
		void			attack(Fighter *target) noexcept override;

		// Other
		void			interact_with(Character& character);
		void			on_interact(Player& player) override;
};
