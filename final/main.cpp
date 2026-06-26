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

int	main(void)
{
	return (0);
}
