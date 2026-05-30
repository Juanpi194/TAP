#include <iostream>

namespace first
{
	int x = 10;
}

int	main(void)
{
	using namespace first;

	std::cout << x << std::endl;

	using namespace std;
	cout << "Using std namespace" << endl;

	using std::cout;
	cout << "Using cout directly" << std::endl;
	return (0);
}