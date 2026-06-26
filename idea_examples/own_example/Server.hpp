#pragma once
#include <string>
#include <list>
#include <mutex>
#include <netinet/in.h>

#include "World.hpp"	// IT IS NEEDED, because 'World' is being used and we need its size (with pointer it wouldn't be required).
#include "Player.hpp"

#define	DEFAULT_PORT	8080
#define	MAX_CLIENTS		10
#define	MAX_MSG_LEN		256

class Server
{
	private:
		int					socket_id;
		sockaddr_in			address;
		std::list<Player>	player_list;	// The player will be initialized in the list, so it shouldn't be a pointer
		World				world;
		std::mutex			mtx;
	public:
		// Constructors
		Server(const std::string& world_name);	// Socket will be initialized in the constructor. Throws exception if fails
		Server(const Server& server) = delete;
		~Server();

		// Operators
		// Nothing required

		// Getters and setters
		int							get_socket_id(void) const;
		const sockaddr_in&			get_address(void) const;
		std::list<Player>&			get_player_list(void);	// Not const so it can be modified
		const std::list<Player>&	get_player_list(void) const;
		const World&				get_world(void) const;

		// Utils
		// TODO: qol functions...
		Player&	connect_user(const std::string& name, int client_fd);
		void	close_connections(void);
};
