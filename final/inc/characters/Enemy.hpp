#pragma once

#include "NPC.hpp"
#include "Fighter.hpp"

class Enemy: public NPC, public Fighter
{
	private:
		unsigned int	gold;	// Will be dropped when defeated
	public:
		// Constructors
		Enemy(const std::string& name, const std::string& description, t_stats stats, unsigned int coins);
		Enemy(const Enemy& enemy);
		virtual	~Enemy(void) = default;

		// Operators
		Enemy&	operator=(const Enemy& other) = delete;

		// Getters and setters
		unsigned int	get_gold(void) const noexcept;

		// Utils
		// TODO
};
