#include <iostream>

typedef int	number_t;
typedef std::string text_t;

//It seems to be more popular to use the word 'using' for these cases.
using decimal_number = double;

int	main(void)
{
	int				num1;
	number_t		num2;
	std::string		text1;
	text_t			text2;
	double			decimal_num1;
	decimal_number	decimal_num2;

	num1 = 10;
	num2 = 20;
	text1 = "This is a text";
	text2 = "This is a different text";
	decimal_num1 = 10.5;
	decimal_num2 = 23.12;
	std::cout << num1 << std::endl;
	std::cout << num2 << std::endl;
	std::cout << text1 << std::endl;
	std::cout << text2 << std::endl;
	std::cout << decimal_num1 << std::endl;
	std::cout << decimal_num2 << std::endl;
	return (0);
}