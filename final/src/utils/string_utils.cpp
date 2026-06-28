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

bool	starts_with(const std::string& str, const std::string& prefix)
{
	if (prefix.size() > str.size())
		return (false);

	if (str.compare(0, prefix.size(), prefix) == 0)
		return (true);
	return (false);
}

bool	ends_with(const std::string& str, const std::string& suffix)
{
	if (suffix.size() > str.size())
		return (false);

	if (str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0)
		return (true);
	return (false);
}
