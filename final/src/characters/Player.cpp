#include "characters/Player.hpp"

// Constructors ---------------------------------------------------------------

Player::Player(const std::string& name):
	Character(name),
	Fighter(name, {10, 10}),
	current_location(nullptr),
	gold(0)
{
	
}

// Getters and setters --------------------------------------------------------

Room						*Player::get_current_location(void) const noexcept
{
	return (current_location);
}

unsigned int				Player::get_gold(void) const noexcept
{
	return (gold);
}

std::list<Enemy*>&			Player::get_beaten_enemies(void) noexcept
{
	return (beaten_enemies);
}

const std::list<Enemy*>&	Player::get_beaten_enemies(void) const noexcept
{
	return (beaten_enemies);
}

std::list<Quest>&			Player::get_quest_list(void) noexcept
{
	return (quest_list);
}

const std::list<Quest>&		Player::get_quest_list(void) const noexcept
{
	return (quest_list);
}

// Utils ----------------------------------------------------------------------

void	Player::buy_item(const Merchant& merchant, Item *item)
{
	// TODO: Logic...
}

void	Player::move(void)
{
	// TODO: Change location through Zone adyacent zones, ...
}

void	Player::attack(Fighter *target) noexcept
{
	// TODO: Attack logic...
}

void	Player::interact_with(Character& character)
{
	// TODO: Logic...
	character.on_interact(*this);
}

void	Player::on_interact(Player& player)
{
	// TODO: Logic...
}
