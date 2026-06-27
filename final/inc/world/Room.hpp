#pragma once
#include <string>
#include <list>
#include <map>

class Player;
class NPC;

enum class Direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

class Room
{
	private:
		const std::string			id;
		const std::string			name;
		const std::string			description;
		NPC							*npc;
		Item						*item;
		std::list<Player*>			player_list;
		std::map<Direction, Room*>	adyacent_rooms;
	public:
		// Constructors
		Room(const std::string& id, const std::string& name, const std::string description, NPC *npc);
		Room(const Room& zone) = delete;
		virtual ~Room(void);

		// Operators
		Room&	operator=(const Room& other) = delete;

		// Getters and setters
		std::string					get_id(void) const noexcept;
		std::string					get_name(void) const noexcept;
		std::string					get_description(void) const noexcept;
		NPC							*get_NPC(void) const noexcept;
		std::list<Player*>&			get_player_list(void) noexcept;
		const std::list<Player*>& 	get_player_list(void) const noexcept;

		// Utils
		void			clear(void);
};
