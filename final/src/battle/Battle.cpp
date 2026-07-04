#include "battle/Battle.hpp"

#include <iostream>

#include "utils.hpp"

void	Battle::execute_turn(void)
{
	// TODO: Logic...
	blue.choose_action();
	red.choose_action();
}

// Constructors ---------------------------------------------------------------

Battle::Battle(Fighter& blue, Fighter& red):
	blue(blue),
	red(red),
	turns(0)
{
	// ? REVIEW: Check this logic.
	if (&blue == &red)
		throw std::invalid_argument("Cannot start a battle with the same two fighters.");
}

// Getters and setters --------------------------------------------------------

Fighter&	Battle::get_blue(void) const noexcept
{
	return (blue);
}

Fighter&	Battle::get_red(void) const noexcept
{
	return (red);
}

// Utils ----------------------------------------------------------------------

void	Battle::start_battle(void) noexcept
{
	// TODO: Battle logic
	log("Battle between '" + blue.get_name() + "' and '" + red.get_name() + "' starts!", LogLevel::INFO);
	while (true)
	{
		break ;
	}
}
