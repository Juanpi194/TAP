#pragma once
#include <sys/socket.h>
#include <netinet/in.h>
#include <mutex>
#include <list>
#include <string>

#include "Player.hpp"

#define MAX_PLAYERS 10

class Server
{
    private:
        int					sock;
        sockaddr_in			address;
        std::list<Player>	player_list;
        std::mutex 			mtx;
    public:
        // Constructors
        Server();
        Server(const Server&) = delete;	// No podrá ser implementado
        Server& operator=(const Server&) = delete;	// No podrá ser implementado
        ~Server();

        // Operators
        // TODO

        // Getters
        int							get_sock() const;
        std::list<Player>&			get_player_list();	// Overload
        const std::list<Player>&	get_player_list() const;
        sockaddr_in                 get_address() const;
        const std::mutex&           get_mtx() const;

        // Setters
        // TODO

        // Utils
        bool	private_msg(const std::string& msg, const Player& sender, const Player& target);
        void	public_msg(const std::string& msg, const Player& sender);
        void	add_player(const Player& player);
        bool	remove_player(const Player& target);
};
