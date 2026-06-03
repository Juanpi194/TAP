#include "tap_commands.hpp"
#include <iostream>

const char	*command_to_string(Command command)
{
	switch (command)
	{
		case Command::CONNECT:
			return ("CONNECT");

		// TODO
		default:
			return (nullptr);
	}
}

Command		str_to_command(const std::string& s)
{
	if (s == "CONNECT")
		return (Command::CONNECT);
	// TODO

	throw std::invalid_argument("Invalid command to parse");
}

const char	*event_to_string(Event event)
{
	switch (event)
	{
		// TODO
		default:
			return (nullptr);
	}
}

Event		str_to_event(const std::string& s)
{
	// TODO
	throw std::invalid_argument("Invalid event to parse");
}

const char	*error_to_string(Error error)
{
	switch (error)
	{
		case Error::NAME_IN_USE:
			return ("NAME IN USE");
		// TODO
		default:
			return (nullptr);
	}
}

Error		str_to_error(const std::string& s)
{
	if (s == "NAME IN USE")
		return (Error::NAME_IN_USE);
	// TODO
	throw std::invalid_argument("Invalid error to parse");
}
