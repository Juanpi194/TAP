#include <iostream>

int	main(void)
{
	int	num1 = 10;
	int	num2 = 2;
	int	result;

	result = num1 + num2;
	std::cout << result << std::endl;
	// ==========================================================
	result = num1 - num2;
	std::cout << result << std::endl;
	// ==========================================================
	result = num1 * num2;
	std::cout << result << std::endl;
	// ==========================================================
	result = num1 / num2;
	std::cout << result << std::endl;
	// ==========================================================
	result = num1 % num2;
	std::cout << result << std::endl;
	// ==========================================================
	result += 20;
	std::cout << result << std::endl;
	// ==========================================================
	result *= 2;
	std::cout << result << std::endl;
	return (0);
}