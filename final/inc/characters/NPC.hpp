#pragma once

#include "characters/Character.hpp"

class NPC: public virtual Character
{
	private:
		const std::string	description;
	public:
		// Constructors -------------------------------------------------------

		NPC(const std::string& name, const std::string& description);
		NPC(const NPC& npc);
		~NPC(void) = default;

		// Operators ----------------------------------------------------------

		NPC&	operator=(const NPC& other) = delete;

		// Getters and setters ------------------------------------------------

		std::string	get_description(void) const noexcept;

		// Utils --------------------------------------------------------------

		// TODO: Util functions
};
