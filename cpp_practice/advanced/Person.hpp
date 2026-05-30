#pragma once	// Same as IFNDEF ...
#include <string>	// String

class Person
{
	private:
		unsigned int		age;
		std::string			name;
		static unsigned int	count;
	public:
		// Constructors
		Person(void);	// Default constructor
		Person(unsigned int age, const std::string& name);	// Other constructor
		~Person(void) = default;	// Destructor ('= default' only if default behavior)

		// Operators
		Person&	operator=(const Person& other);
		bool	operator==(const Person& other) const;

		// Getters
		unsigned int		get_age(void) const;
		const std::string&	get_name(void) const;
		static unsigned int	get_count(void);

		// Setters
		void	set_age(unsigned int age);
		void	set_name(const std::string& name);

		// Utils
		void	greet(void) const;
};
