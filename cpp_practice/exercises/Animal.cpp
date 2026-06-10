#include <iostream>
#include <string>

class Animal
{
	private:
		std::string	name;
	public:
		// Constructors
		Animal(const std::string& name):
			name(name)
		{
			if (name.empty())
				throw std::invalid_argument("Name cannot be empty");
		}
		virtual ~Animal(void) = default;

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

class Dog final: public Animal
{
	public:
		// Constructors
		Dog(const std::string& name):
			Animal(name)
		{
		}
		~Dog(void) = default;

		// Operators
		// Not needed

		// Getters and setters
		// None

		// Utils
		void	speak(void) const override
		{
			std::cout << "I'm a dog, and my sound is 'woof woof'!" << std::endl;
		}
};

class Cat final: public Animal
{
	public:
		// Constructors
		Cat(const std::string& name):
			Animal(name)
		{
		}
		~Cat(void) = default;

		// Operators
		// Not needed

		// Getters and setters
		// None

		// Utils
		void	speak(void) const override
		{
			std::cout << "I'm a cat, and my sound is 'meow meow'!" << std::endl;
		}
};

int	main(void)
{
	Animal	generic("Juanpi");
	Dog		doggie("Pablo");
	Cat		kittie("Diego");

	generic.speak();
	doggie.speak();
	kittie.speak();
	return (0);
}

