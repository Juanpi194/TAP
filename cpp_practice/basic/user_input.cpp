#include <iostream>

int	main(void)
{
	std::string name;
	int			age;

	std::cout << "What's your name? ";
	std::cin >> name;
	std::cout << "What's your age? ";
	std::cin >> age;
	std::cout << "Your name is: " << name << "and you are " << age << " years old!\n";
	return (0);
}