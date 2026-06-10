#include <iostream>
#include <string>

void	trim_str(std::string& s, bool middle = true)
{
	std::string	result;

	// End
    while (!s.empty() && (s.back() == '\n' || s.back() == '\r' || s.back() == ' '))
        s.pop_back();
	// Beginning
	while (!s.empty() && (s.front() == '\n' || s.front() == '\r' || s.front() == ' '))
		s.erase(0, 1);
	// Removing duplicated in the middle
	if (!middle)
		return ;
	for (char c : s)
	{
		if (c != ' ')
			result += c;
		else if (result.back() != ' ')
			result += c;
	}
	s = result;
}

int	main(void)
{
	std::string	str = "   Hola  que    tal   ";

	trim_str(str);
	std::cout << str << std::endl;
	return (0);
}
