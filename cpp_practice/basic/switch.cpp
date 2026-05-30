#include <iostream>

int	main(void)
{
	int	month;

	std::cout << "Enter the number of the month: ";
	std::cin >> month;
	switch(month)
	{
		case 1:
			std::cout << "It is January";
			break;
		case 2:
			std::cout << "It is February";
			break;
		case 3:
			std::cout << "It is March";
			break;
		case 4:
			std::cout << "It is April";
			break;
		case 5:
			std::cout << "It is May";
			break;
		case 6:
			std::cout << "It is June";
			break;
		default:
			std::cout << "Not correct input or bigger than June";
			break;
	}
	return (0);
}