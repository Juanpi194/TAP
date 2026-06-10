#include <iostream>
#include <string>

template <typename T>
T	get_max(T first, T second)
{
	if (first >= second)
		return (first);
	else
		return (second);
}

template <typename T, size_t S>
class Array
{
	private:
		size_t	size;
		T		data[S];
	public:
		// Constructors
		// Default...

		// Operators
		// Not needed

		// Getters and setters
		size_t	get_size(void) const noexcept
		{
			return (S);
		}

		T		*get_data(void) const noexcept
		{
			return (data);
		}

		// Utils
		// TODO
};

int	main(void)
{
	int	num1 = 10;
	int	num2 = 20;
	std::string	s1 = "Hey";
	std::string	s2 = "Bye";

	std::cout << get_max(num1, num2) << std::endl;	// Comparing numbers
	std::cout << get_max(s1, s2) << std::endl;		// Comparing strings

	Array<int, 10>	array;
	std::cout << array.get_size() << std::endl;
	return (0);
}
