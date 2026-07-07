#pragma once

#include <iostream>

class Character
{
	private:
		std::string	name;
	public:
		Character(const std::string& name);

		std::string	get_name(void) const noexcept;
		virtual void	fight(void) = 0;
};
