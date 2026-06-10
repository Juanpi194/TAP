#include <iostream>
#include <string>

class MathException final: public std::exception
{
	private:
		std::string	message;
	public:
		// Constructors
		MathException():
			message("Math error")
		{
		}
		explicit MathException(const std::string& msg):
			message(msg)
		{
		}

		// Utils
		const char	*what() const noexcept override
		{
			return (message.c_str());
		}
};

float	divide(int num, int divisor)
{
	if (divisor == 0)
		throw MathException("Can't divide by zero");
	return (num / divisor);
}

int	main(void)
{
	std::cout << divide(40, 0) << std::endl;
	return (0);
}
