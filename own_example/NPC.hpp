#pragma once
#include <string>

class Player;

class NPC
{
	private:
		std::string	name;
		std::string	description;
	public:
		// Constructors
		NPC(const std::string& name, const std::string& description);
		NPC(const NPC& npc);
		virtual ~NPC() = default;

		// Operators
		NPC&	operator=(const NPC& other);

		// Getters and setters
		const std::string&	get_name(void) const;
		const std::string&	get_description(void) const;

		// Utils
		virtual void	interact(Player& player) = 0;
};
