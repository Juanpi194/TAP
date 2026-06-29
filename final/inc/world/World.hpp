#pragma once

#include "world/Room.hpp"

class World
{
	private:
		const std::string	name;
		std::list<Room*>	rooms;

		static constexpr size_t	MAX_NAME_LENGTH = 18;
		static constexpr bool	TITLE_NAME = true;

		bool	validate_json(const std::string& json_path);
	public:
		// Constructors -------------------------------------------------------

		/**
		 * @brief	Default world.
		 */
		World(const std::string& name);

		/**
		 * @brief	World with data in the json.
		 */
		World(const std::string& name, const std::string& json_path);
		World(const World& world) = delete;

		/**
		 * @brief	All characters, items, ... must be freed from here.
		 * 			They will only exist in this instance.
		 * 
		 */
		~World(void);

		// Operators
		World&	operator=(const World& other) = delete;

		// Getters and setters
		std::string				get_name(void) const noexcept;
		std::list<Room*>&		get_rooms(void) noexcept;
		const std::list<Room*>&	get_rooms(void) const noexcept;

		// Utils
		void	reset_world(void);
};
