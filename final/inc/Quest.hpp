#pragma once
#include <string>

class Quest
{
	private:
		const std::string	description;
		bool				completed;
	public:
		// Constructors
		Quest(const std::string& description);
		Quest(const Quest& quest);
		~Quest(void) = default;

		// Operators
		Quest&	operator=(const Quest& other) = delete;

		// Getters and setters
		std::string	get_description(void) const noexcept;
		bool		is_completed(void) const noexcept;

		void		set_completed(bool completed) noexcept;

		// Utils
		// TODO
};
