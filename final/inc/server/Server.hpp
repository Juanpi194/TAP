#pragma once
#include <mutex>

#include "server/PlayerConnection.hpp"
#include "world/World.hpp"

class ServerOwner;

class Server
{
	private:
		const int					sock;
		ServerOwner					*owner;
		World						world;
		std::list<PlayerConnection>	players;
		std::mutex					mtx;
		bool						on;
	public:
		// Constructors
		Server(void);
		Server(const Server& server) = delete;
		~Server(void);

		// Operators
		Server&	operator=(const Server& other) = delete;

		// Getters and setters
		ServerOwner							*get_server_owner(void) const noexcept;
		World&								get_world(void) noexcept;
		const World&						get_world(void) const noexcept;
		std::list<PlayerConnection>&		get_players(void) noexcept;
		const std::list<PlayerConnection>&	get_players(void) const noexcept;
		bool								is_on(void) const noexcept;

		void	set_owner(ServerOwner *owner) noexcept;

		// Utils
		void	start(void);
		void	stop(void);
		void	send_msg_to(int dst, const std::string& msg);
		void	broadcast(const std::string& msg);
		void	connect_player(PlayerConnection& player);
		void	disconnect_player(PlayerConnection& player);
};
