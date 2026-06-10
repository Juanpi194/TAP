#include <iostream>
#include <string>

class Animal
{
	private:
		std::string	name;
	public:
		// Constructors
		Animal(void)	// Needed for the array
		{
			std::cout << "Animal default constructor used!" << std::endl;
		}
		Animal(const std::string& name):
			name(name)
		{
			if (name.empty())
				throw std::invalid_argument("Name cannot be empty");
			std::cout << "Animal '" << name << "' created!" << std::endl;
		}
		~Animal(void)
		{
			std::cout << "Animal '" << name << "' destroyed!" << std::endl;
		};

		// Operators
		// Not needed

		// Getters and setters
		std::string	get_name(void) const	// Returning a copy in purpose
		{
			return (name);
		}

		// Utils
		virtual void	speak(void) const
		{
			std::cout << "I'm a generic animal, and i don't have a specific sound!" << std::endl;
		}
};

int	main(void)
{
	Animal	a1("Juanpi");
	{
		Animal	a2("David");
		Animal	a3("Marcos");
	}
	Animal	*a_ptr = new Animal("Carlos");
	{
		Animal	a4("Luis");
	}
	delete (a_ptr);

	// Array
	Animal	*animals = new Animal[5];	// We need a default constructor for this
	delete[] (animals);
	return (0);
}
