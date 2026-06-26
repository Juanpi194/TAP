#pragma once

#include "Room.hpp"

class World
{
	private:
		const std::string	id;
		const std::string	name;
		const std::string	description;
		std::list<Room*>	rooms;
	public:
		// Constructors
		World(const std::string& id, const std::string& name, const std::string& description, std::list<Room*>& rooms);
		World(const World& world) = delete;
		~World(void) = default;

		// Operators
		World&	operator=(const World& other) = delete;

		// Getters and setters
		std::string			get_id(void) const noexcept;
		std::string			get_name(void) const noexcept;
		std::string			get_description(void) const noexcept;
		std::list<Room*>	get_rooms(void) const noexcept;

		// Utils
		void	reset_world(void);
};
