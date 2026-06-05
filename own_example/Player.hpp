#pragma once
#include <string>
#include <list>

#include "Quest.hpp"
#include "Item.hpp"

#define	MAX_ITEMS	30

class Room;

class Player
{
	private:
		std::string			name;
		std::list<Quest>	quest_list;
		std::list<Item*>	item_list;
		int					client_fd;
		unsigned int		id;
		bool				connected;
		Room*				current_room;
		unsigned int		n_sent_messages;
		static unsigned int	available_id;
	public:
		// Constructors
		Player(const std::string& name, int client_fd);	// Lists will start being empty, room will point to nullptr
		Player(const Player& player);
		~Player() = default;

		// Operators
		Player&	operator=(const Player& other);

		// Getters and setters
		const std::string&		get_name(void) const;
		const std::list<Quest>&	get_quest_list(void) const;
		const std::list<Item*>&	get_item_list(void) const;
		int						get_client_fd(void) const;
		unsigned int			get_id(void) const;
		bool					is_connected(void) const;
		Room*					get_current_room(void) const;
		unsigned int			get_n_sent_messages(void) const;
		static unsigned int		get_available_id(void);
		void					set_client_fd(int fd);
		void					set_connected(bool connected);
		void					set_current_room(Room *room);

		// Utils
		void	add_quest(const Quest& quest);
		void	remove_quest(const Quest& quest);
		void	complete_quest(const std::string& quest_description);
		void	add_item(Item *item);
		void	remove_item(Item *item);
		void	show_player_info(void) const;
		void	increment_sent_messages(void);
		void	disconnect(void);
};
