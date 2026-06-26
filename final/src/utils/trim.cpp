#include "utils.hpp"


void	trim_str(std::string& s, bool middle)
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
