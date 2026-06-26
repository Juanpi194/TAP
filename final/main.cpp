#include <iostream>
#include <string>

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

class Item
{
	private:
		std::string	name;
		std::string	description;
	public:
		// Constructors
		Item(const std::string& name, const std::string& description);
		Item(const Item& item);
		~Item(void) = default;

		// Operators
		Item&	operator=(const Item& other);

		// Getters and setters
		std::string	get_name(void) const noexcept;
		std::string	get_description(void) const noexcept;

		// Utils
		// TODO
};

class Player
{
	private:
		std::string	name;
		int			client_fd;
		Item		*items;
	public:
		// Constructors
		Player(const std::string& name, int client_fd);
		Player(const Player& player);
		~Player(void) = default;

		// Operators
		Player& operator=(const Player& other);

		// Getters and setters
		std::string	get_name(void) const noexcept;
		int			get_client_fd(void) const noexcept;
		void		set_name(void);
		void		set_client_fd(void);

		// Utils
		void		disconnect(void) noexcept;
};

int	main(void)
{
	return (0);
}
