#include <iostream>
#include <string>

class ParseException final: public std::exception
{
	private:
		std::string	msg;
	public:
		ParseException(void):
			msg("Parse exception")
		{
		}
		explicit ParseException(const std::string& msg):
			msg(msg)
		{
		}

		// Utils
		const char	*what() const noexcept override
		{
			return (msg.c_str());
		}
};

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

struct command_parser
{
	std::string	command;
	std::string	scope;
	std::string	msg;
};

command_parser	parse_line(std::string line)
{
	command_parser	result;
	size_t			command_pos;
	size_t			scope_pos;
	size_t			msg_pos;
	std::string		scope_and_msg;
	std::string		msg;

	trim_str(line);
	command_pos = line.find(" ");
	if (command_pos == std::string::npos)	// npos is the highest value (which means not found)
		throw ParseException("Invalid command");
	result.command = line.substr(0, command_pos);
	scope_and_msg = line.substr(command_pos);
	trim_str(scope_and_msg);
	scope_pos = scope_and_msg.find(" ");
	if (scope_pos == std::string::npos)
		throw ParseException("No scope after command");
	result.scope = scope_and_msg.substr(0, scope_pos);
	msg = scope_and_msg.substr(scope_pos);
	trim_str(msg);
	if (msg.empty())
		throw ParseException("No message sent");
	result.msg = msg;
	return (result);
}


int	main(void)
{
	std::string	line = "CHAT GLOBAL Hello";

	command_parser	parse = parse_line(line);
	std::cout << "Command: " << parse.command << std::endl;
	std::cout << "Scope: " << parse.scope << std::endl;
	std::cout << "Message: " << parse.msg << std::endl;
	return (0);
}
