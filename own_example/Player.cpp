#include "Player.hpp"

unsigned int	Player::available_id = 0;

// Constructors
Player::Player(const std::string& name, int client_fd):
	name(name),
	client_fd(client_fd),
	id(available_id++),
	connected(true),	// When the player is being created, starts as connected
	current_room(nullptr)
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
	current_room(player.current_room)
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
	// TODO: Check if quest's description is already in the list before adding it
	quest_list.push_back(quest);
}

void	Player::remove_quest(const Quest& quest)
{
	quest_list.remove(quest);
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
