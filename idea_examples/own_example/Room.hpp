#pragma once
#include <string>
#include <list>

class Item;
class NPC;
class Player;

class Room
{
	private:
		std::string			name;
		std::string			description;
		std::list<Item*>	items_in_room;	// Item is abstract, so it must be a pointer to them.
		std::list<NPC*>		npcs_in_room;	// Same as above.
		std::list<Player*>	players_in_room;	// These are references to the players, the real players are in the server. Without pointer, they would be copies.
	public:
		// Constructors
		Room(const std::string& name, const std::string& description);
		Room(const Room& room);
		~Room() = default;

		// Operators
		Room&	operator=(const Room& other);

		// Getters and setters
		const std::string&			get_name(void) const;
		const std::string&			get_description(void) const;
		const std::list<Item*>&		get_items_in_room(void) const;
		const std::list<NPC*>&		get_npcs_in_room(void) const;
		const std::list<Player*>&	get_players_in_room(void) const;

		// Utils
		// TODO: Add players, ...
};
