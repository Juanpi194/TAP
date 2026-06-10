#include <iostream>
#include <string>

class Vector2D
{
	private:
		int	x;
		int	y;
		Vector2D(void);	// So it cannot be created
	public:
		// Constructors
		Vector2D(int x, int y):
			x(x),
			y(y)
		{
		}

		Vector2D(const Vector2D& vector):
			x(vector.x),
			y(vector.y)
		{
		}

		~Vector2D() = default;

		// Operators
		Vector2D&	operator=(const Vector2D& other)
		{
			if (this == &other)
				return (*this);
			x = other.x;
			y = other.y;
			return (*this);
		}

		Vector2D&	operator+(const Vector2D& other)
		{
			// if (this == &other)
				// return (*this);
			x += other.x;
			y += other.y;
			return (*this);
		}

		Vector2D&	operator-(const Vector2D& other)
		{
			// if (this == &other)
				// return (*this);
			x -= other.x;
			y -= other.y;
			return (*this);
		}


		// Getters and setters
		int		get_x(void) const noexcept
		{
			return (x);
		}

		int		get_y(void) const noexcept
		{
			return (y);
		}

		// Utils
};

int	main(void)
{
	Vector2D	vector1(10, 20);
	Vector2D	vector2(20, 30);

	Vector2D	result = vector1 + vector2;
	std::cout << result.get_x() << std::endl;
	std::cout << result.get_y() << std::endl;
	return (0);
}
