#pragma once
#include <string>

class Server;

class ServerOwner
{
	private:
		std::string	name;
		std::string	password;
		Server	*server;
	public:
		// Constructors
		ServerOwner(const std::string& name, Server *server);
		ServerOwner(const ServerOwner& server) = delete;
		~ServerOwner(void);

		// Operators
		ServerOwner&	operator=(const ServerOwner& other) = delete;

		// Getters and setters
		std::string	get_name(void) const noexcept;
		Server		*get_server(void) const noexcept;

		void	set_name(const std::string& name);
		// void	set_server(Server *server);

		// Utils
		void	change_password(void);
		void	shutdown_server(void);
};
