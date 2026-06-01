#pragma once
#include <string>

#define MAX_NAME_LEN 	25
#define MAX_MSG_LEN		256

class Player
{
	private:
		unsigned int		fd;
		std::string			name;
		unsigned int		id;
		static unsigned int	available_id;
	public:
		// Constructors
		Player(unsigned int fd);
		Player(unsigned int fd, const std::string& name);
		Player(const Player& other);
		~Player() = default;

		// Operators
		Player& operator=(const Player& other);
		bool	operator==(const Player& other) const;

		// Getters
		unsigned int		get_fd() const;
		const std::string&	get_name() const;
		unsigned int		get_id() const;
		static unsigned int	get_available_id();

		// Setters
		void	set_name(const std::string& name);

		// Utils
        bool    ask_name();
};
