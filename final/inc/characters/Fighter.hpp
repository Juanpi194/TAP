#pragma once

#include "characters/Character.hpp"

enum Status
{
	HEALTHY,
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
	private:
		static constexpr unsigned int	MIN_HP = 10;
		static constexpr unsigned int	MAX_HP = 100;
		static constexpr unsigned int	MIN_STRENGTH = 5;
		static constexpr unsigned int	MAX_STRENGTH = 80;
	protected:
		t_stats			stats;
		Status			status;
	public:
		// Constructors -------------------------------------------------------

		Fighter(const std::string& name, t_stats stats);
		Fighter(const Fighter& fighter);
		virtual ~Fighter(void) = default;

		// Operators ----------------------------------------------------------

		Fighter&	operator=(const Fighter& other) = delete;

		// Getters and setters ------------------------------------------------

		t_stats			get_stats(void) const noexcept;
		Status			get_status(void) const noexcept;

		void	set_status(Status status) noexcept;

		// Utils --------------------------------------------------------------

		virtual void	attack(Fighter *target) noexcept = 0;
		void			apply_status(Status status) noexcept;
};
