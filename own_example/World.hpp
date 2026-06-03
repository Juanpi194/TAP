#pragma once
#include <list>
#include <string>

class Room;
class Player;

class World
{
	private:
		std::string				name;
		// std::list<Player>		player_list;	// Will be managed by the server.
		std::list<Room*>		room_list;
	public:
		// Constructors
		World(const std::string& name);
		World(const World& world);
		~World() = default;

		// Operators
		World&	operator=(const World& other);

		// Getters and setters
		const std::string&			get_name(void) const;
		// const std::list<Player>&	get_player_list(void) const;
		const std::list<Room*>&		get_room_list(void) const;

		// Utils
		// TODO: qol functions...
};
