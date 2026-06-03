#include <iostream>

void	func_no_except(int&& x) noexcept
{
	if (x < 0)
		std::cout << "X is invalid, but no exception was thrown" << std::endl;
}

void	func(int&& x)
{
	if (x < 0)
		throw std::invalid_argument("x cannot be negative");
}

int	main(void)
{
	try
	{
		func(-1);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	func_no_except(-1);
	return (0);
}