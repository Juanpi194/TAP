#pragma once

#include "Character.hpp"

enum Status
{
	NONE,
	POISON,
	BURNT,
	FROZEN
};

struct t_stats
{
	unsigned int	hp;
	unsigned int	strength;
};

// Mixin / Abstract class with just pure virtual methods and attributes (not an interface)
class Fighter: public virtual Character
{
	protected:
		t_stats			stats;
		Status			status;
	public:
		// Constructors
		Fighter(t_stats stats);
		Fighter(const Fighter& fighter);
		virtual ~Fighter(void) = default;

		// Operators
		Fighter&	operator=(const Fighter& other) = delete;

		// Getters and setters
		t_stats			get_stats(void) const noexcept;
		Status			get_status(void) const noexcept;

		void	set_status(Status status);

		// Utils
		virtual void	attack(Fighter *target) noexcept = 0;
		void			apply_status(Status status) noexcept;
};
