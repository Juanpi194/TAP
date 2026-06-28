#include <iostream>
#include <string>

#ifndef WOW
	bool	debug_mode = false;
#else
	bool	debug_mode = true;
#endif

#include "utils.hpp"
#include "Quest.hpp"
#include "characters/Character.hpp"
#include "characters/Player.hpp"
#include "characters/Fighter.hpp"
#include "characters/Merchant.hpp"
#include "characters/QuestGiver.hpp"
#include "items/Item.hpp"
#include "items/Consumable.hpp"
#include "server/PlayerConnection.hpp"
#include "server/Server.hpp"
#include "server/ServerOwner.hpp"
#include "world/Room.hpp"
#include "world/World.hpp"

int	main(void)
{
	// SHORT IDEA OF HOW TO MANAGE DEBUG, flag in top of this file

	if (debug_mode)
	{
		// No server
		std::cout << "No server will be started" << std::endl;
	}
	else
	{
		// Server
		ServerOwner	owner("Marcos", nullptr);
		std::cout << "Server started" << std::endl;
	}
	return (0);
}
