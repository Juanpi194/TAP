#include <iostream>
#include <string>
#include <cstring>

class Person
{
	private:
		int			age;
		std::string	name;
	public:
		// Constructors
		Person(int age, const std::string& name)
		{
			std::cout << "Person " << name << " created" << std::endl;
			this->age = age;
			this->name = name;
		}
		
		Person(const Person& person)
		{
			std::cout << "Person " << person.name << " got copied" << std::endl;
			age = person.age;
			name = person.name;
		}

		~Person()
		{
			std::cout << "Person " << name << " destroyed" << std::endl;
		}

		// Operators
		Person&	operator=(const Person& other)
		{
			std::cout << "Person operator= called (" << other.name << ")" << std::endl;
			if (this == &other)
				return (*this);
			this->age = other.age;
			this->name = other.name;
			return (*this);
		}
		bool	operator==(const Person& other)
		{
			if (this->age == other.age)
				return (true);
			return (false);
		}

		// Getters and setters
		int	get_age(void) const
		{
			return (age);
		}

		std::string	get_name(void) const
		{
			return (name);
		}

		// Utils
		virtual void	greet() const
		{
			std::cout << "Hello, i am " << name << ", and i am " << age << " years old" << std::endl;
 		}
};

void	func(Person p)
{
	p.greet();
}


int	main(void)
{
	Person	person(21, "Rocio");
	Person	person2(21, "Nora");
	Person	*person_ptr = new Person(22, "Juanpi");
	// Person	person3 = person + person2;

	std::cout << (person == person2) << std::endl;
	func(person);
	person.greet();
	delete (person_ptr);
	return (0);
}
