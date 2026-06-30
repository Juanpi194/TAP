#include "characters/Fighter.hpp"

#include <iostream>

Fighter::Fighter(const std::string& name, t_stats stats):
	Character(name),
	stats(stats),
	status(Status::HEALTHY)
{
	if (stats.hp < MIN_HP || stats.hp > MAX_HP || stats.strength < MIN_STRENGTH || stats.strength > MAX_STRENGTH)
		throw std::invalid_argument("Fighter stats are not valid.");
}

Fighter::Fighter(const Fighter& fighter):
	Character(fighter.get_name()),
	stats(fighter.stats),
	status(fighter.status)
{
	this->current_room = fighter.current_room;
}

t_stats	Fighter::get_stats(void) const noexcept
{
	return (stats);
}

Status	Fighter::get_status(void) const noexcept
{
	return (status);
}

void	Fighter::set_status(Status status) noexcept
{
	this->status = status;
}

void	Fighter::apply_status(Status status) noexcept
{
	// TODO
}
