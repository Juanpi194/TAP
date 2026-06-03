#include <iostream>

class Player
{
	public:
		std::string	name;
};

int	main(void)
{
	Player	*players;
	players = new Player[5];	// Array
	delete[] (players);			// Cada new tiene su propio delete

	// Acostumbrarse a usar std::bad_alloc (Por si falla la reserva con new)
	return (0);
}
