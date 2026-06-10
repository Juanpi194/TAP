#include <iostream>
#include <string>

class BankAccount
{
	private:
		unsigned int	salary;
		std::string		holder;
		unsigned int	account_number;
	public:
		// Constructors
		BankAccount(unsigned int salary, const std::string& holder, unsigned int account_number):
			salary(salary),
			holder(holder),
			account_number(account_number)
		{
			// if (salary < 0)
			// 	throw std::invalid_argument("Salary cannot be negative");
			if (holder.empty())
				throw std::invalid_argument("Holder name cannot be empty");
		}
		~BankAccount() = default;

		// Operators
		// Not needed

		// Getters and setters
		unsigned int	get_salary(void) const noexcept
		{
			return (salary);
		}

		std::string	get_holder(void) const noexcept	// We return a copy in purpose
		{
			return (holder);
		}

		unsigned int	get_account_number(void) const noexcept
		{
			return (account_number);
		}

		// Utils
		void	deposit(unsigned int quantity) noexcept
		{
			// if (quantity <= 0)
			// 	throw std::invalid_argument("Increment of the salary must be a positive number");
			salary += quantity;
		}

		void	remove(unsigned int quantity)
		{
			if (quantity > salary)
				throw std::invalid_argument("Quantity is greater than actual salary. The operation was not done");
			salary -= quantity;
		}

		void	show_status(void) const noexcept
		{
			std::cout << "Account holder: " << holder << std::endl;
			std::cout << "Account salary: " << salary << std::endl;
			std::cout << "Account number: " << account_number << std::endl;
		}
};

int	main(void)
{
	BankAccount	acc(1000, "Juanpi", 50);

	acc.show_status();
	return (0);
}
