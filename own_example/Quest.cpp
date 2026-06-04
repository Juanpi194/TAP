#include "Quest.hpp"

// Constructors
Quest::Quest(const std::string& description):
	description(description),
	completed(false)
{
}

Quest::Quest(const Quest& quest):
	description(quest.description),
	completed(quest.completed)
{
}

// Operators
Quest&	Quest::operator=(const Quest& other)
{
	if (this == &other)
		return (*this);
	description = other.description;
	completed = other.completed;
	return (*this);
}

bool	Quest::operator==(const Quest& other) const
{
	if (this == &other)
		return (true);
	return (false);
}

// Getters and setters
const std::string&	Quest::get_description(void) const
{
	return (description);
}

bool				Quest::is_completed(void) const
{
	return (completed);
}

void				Quest::set_completed(bool completed)
{
	this->completed = completed;
}

// Utils
// TODO: Add util functions
