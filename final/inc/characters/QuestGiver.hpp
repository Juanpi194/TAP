#pragma once

#include "characters/NPC.hpp"
#include "Quest.hpp"

class QuestGiver: public NPC
{
	private:
		Quest	quest;
	public:
		// Constructors
		QuestGiver(const std::string& name, const std::string& description, Quest& quest);
		QuestGiver(const QuestGiver& quest_giver);
		~QuestGiver(void) = default;

		// Operators
		QuestGiver&	operator=(const QuestGiver& other) = delete;

		// Getters and setters
		Quest	get_quest(void) const noexcept;	// Copy of the quest

		// Utils
		void	on_interact(Player& player) override;
};
