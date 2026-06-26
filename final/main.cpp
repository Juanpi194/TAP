#include <iostream>
#include <string>

#ifndef WOW
	bool	debug_mode = false;
#else
	bool	debug_mode = true;
#endif

class Quest
{
	private:
		unsigned int	id;
		std::string		description;
	public:
		// Constructors
		Quest(unsigned int id, const std::string& description);
		Quest(const Quest& quest);
		~Quest(void) = default;

		// Operators
		Quest&	operator=(const Quest& other);

		// Getters and setters
		unsigned int	get_id(void) const noexcept;
		std::string		get_description(void) const noexcept;

		// Utils
		// TODO
};

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
		std::cout << "Server started" << std::endl;
	}
	return (0);
}
