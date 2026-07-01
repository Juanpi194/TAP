#include "characters/QuestGiver.hpp"

// Constructors ---------------------------------------------------------------

QuestGiver::QuestGiver(const std::string& name, const std::string& description, Quest& quest):
	Character(name),
	NPC(name, description),
	quest(quest)
{
}

QuestGiver::QuestGiver(const QuestGiver& quest_giver):
	Character(quest_giver.get_name()),
	NPC(quest_giver.get_name(), quest_giver.get_description()),
	quest(quest_giver.quest)
{
	this->current_room = current_room;
}

// Getters and setters --------------------------------------------------------

Quest	QuestGiver::get_quest(void) const noexcept
{
	return (quest);
}

// Utils ----------------------------------------------------------------------

void	QuestGiver::on_interact(Player& player)
{
	// TODO: Logic ...
}
