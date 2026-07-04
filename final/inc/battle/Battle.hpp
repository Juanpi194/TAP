#pragma once

#include "characters/Fighter.hpp"

class Battle
{
	private:
		Fighter&		blue;
		Fighter&		red;
		unsigned int	turns;

		void	execute_turn(void);
	public:
		// Constructors -------------------------------------------------------

		Battle(Fighter& blue, Fighter& red);
		Battle(const Battle& battle) = delete;
		~Battle(void) = default;

		// Operators ----------------------------------------------------------

		Battle&	operator=(const Battle& other) = delete;

		// Getters and setters ------------------------------------------------

		Fighter&	get_blue(void) const noexcept;
		Fighter&	get_red(void) const noexcept;

		// Utils --------------------------------------------------------------

		void	start_battle(void) noexcept;
};
