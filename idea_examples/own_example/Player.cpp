#include "Player.hpp"
#include <iostream>

#include "utils.hpp"

unsigned int	Player::available_id = 0;

// Constructors
Player::Player(const std::string& name, int client_fd):
	name(name),
	client_fd(client_fd),
	id(available_id++),
	connected(true),	// When the player is being created, starts as connected
	current_room(nullptr),
	n_sent_messages(0)
{
	// Lists will start being empty, room will point to nullptr

}	
Player::Player(const Player& player):
	name(player.name),
	quest_list(player.quest_list),
	item_list(player.item_list),
	client_fd(player.client_fd),
	id(player.id),
	connected(player.connected),
	current_room(player.current_room),
	n_sent_messages(player.n_sent_messages)
{
}

// Operators
Player&	Player::operator=(const Player& other)
{
	if (this == &other)
		return (*this);
	name = other.name;
	quest_list = other.quest_list;	// This list is full of copies, which is the objective
	item_list = other.item_list;	// This list makes copies of the pointers, which points to the same thing, and that's not the objective :(
	client_fd = other.client_fd;
	id = other.id;
	connected = other.connected;
	current_room = other.current_room;
	n_sent_messages = other.n_sent_messages;
	return (*this);
}

// Getters and setters
const std::string&		Player::get_name(void) const
{
	return (name);
}

const std::list<Quest>&	Player::get_quest_list(void) const
{
	return (quest_list);
}

const std::list<Item*>&	Player::get_item_list(void) const
{
	return (item_list);
}

int						Player::get_client_fd(void) const
{
	return (client_fd);
}

unsigned int			Player::get_id(void) const
{
	return (id);
}

bool					Player::is_connected(void) const
{
	return (connected);
}

Room*					Player::get_current_room(void) const
{
	return (current_room);
}

unsigned int			Player::get_n_sent_messages(void) const
{
	return (n_sent_messages);
}

void					Player::set_client_fd(int fd)
{
	if (fd < 0)
		return ;
	// TODO: Check if fd is already in use (we need the player list for that)
	client_fd = fd;
}

void					Player::set_connected(bool connected)
{
	this->connected = connected;
}

void					Player::set_current_room(Room *room)
{
	// TODO: In the future, make moving to null an option
	// (being in any room can make sense when selecting room for example)
	if (!room)
		return ;
	this->current_room = room;
}

// Utils
void	Player::add_quest(const Quest& quest)
{
	const std::string	msg = "You received the quest: " + quest.get_description() + "\n";

	for (Quest& q: quest_list)
	{
		if (q.get_description() == quest.get_description())
			return ;
	}
	quest_list.push_back(quest);
	send_msg(get_colored_str(msg, Color::BRIGHT_YELLOW), client_fd);
}

void	Player::remove_quest(const Quest& quest)
{
	quest_list.remove(quest);
}

void	Player::complete_quest(const std::string& quest_description)
{
	const std::string	completed_msg = "Quest '" + quest_description + "' completed! Congratulations!\n";
	const std::string	general_msg = name + " completed the quest: " + quest_description + "\n";

	for (Quest& quest: quest_list)
	{
		if (quest.get_description() == quest_description)
		{
			if (quest.is_completed())
				return ;
			quest.set_completed(true);
			send_msg(get_colored_str(completed_msg, Color::BRIGHT_CYAN), client_fd);
			std::cout << get_colored_str(general_msg, Color::BRIGHT_GREEN);
			return ;
		}
	}
	throw std::runtime_error("Wrong quest descriptioon: " + quest_description);
}

void	Player::add_item(Item *item)
{
	if (!item)
		return ;
	if (item_list.size() < MAX_ITEMS)
		item_list.push_back(item);
	else
	{
		// TODO: Message of not adding item because of no space
	}
}

void	Player::remove_item(Item *item)
{
	if (!item)
		return ;
	item_list.remove(item);
	// TODO: If not found, let user know
}

void	Player::show_player_info(void) const
{
	std::string	final_msg;

	final_msg += ("Name: " + name + "\n");
	final_msg += "Quests: \n===\n";
	for (const Quest& quest: quest_list)
	{
		if (quest_list.size() == 0)
		{
			final_msg += "None\n";
			break;
		}
		final_msg += (quest.get_description() + ": ");
		if (quest.is_completed())
			final_msg += "Completed\n";
		else
			final_msg += "Not completed\n";
	}
	final_msg += "===\n";
	final_msg += "wip";
	std::cout << final_msg << std::endl;
}

void	Player::increment_sent_messages(void)
{
	n_sent_messages++;
	if (n_sent_messages == 1)
	{
		complete_quest("Send your first message");
		Quest quest("Send 10 messages");
		add_quest(quest);
	}
	if (n_sent_messages == 10)
	{
		complete_quest("Send 10 messages");
		Quest quest("Send 100 messages");
		add_quest(quest);
	}
	if (n_sent_messages == 100)
		complete_quest("Send 100 messages");
}

void	Player::disconnect(void)
{
	std::cout << "Player " << name << " disconnected!" << std::endl;
	connected = false;
	close(client_fd);
}
