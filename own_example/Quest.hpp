#pragma once
#include <string>

class Quest
{
	private:
		std::string	description;
		bool		completed;
	public:
		// Constructors
		Quest(const std::string& description);	// 'completed' always starts as False
		Quest(const Quest& quest);
		~Quest() = default;	// Default behavior

		// Operators
		Quest&	operator=(const Quest& other);

		// Getters and setters
		const std::string&	get_description(void) const;
		bool				is_completed(void) const;
		void				set_completed(bool completed);

		// Utils
		// TODO: Add util functions

		// Static
		static constexpr unsigned int	MAX_DESC_LEN = 256;
};
