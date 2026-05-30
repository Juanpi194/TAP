#include <iostream>

int	main(void)
{
	int	num1;
	int	num2;

	num1 = 10;
	num2 = 0;
	if (num1 > num2)
	{
		std::cout << "Num1 (" << num1 << ") is bigger than Num2 (" << num2 << ")\n";
	}
	else if (num1 < num2)
	{
		std::cout << "Num1 (" << num1 << ") is smaller than Num2 (" << num2 << ")\n";
	}
	else
	{
		std::cout << "Num1 (" << num1 << ") is equal to Num2 (" << num2 << ")\n";
	}
	return (0);
}