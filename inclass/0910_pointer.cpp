#include <iostream>

int main()
{
	int x(0);
	x = 5;

	int *y = &x;

	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	std::cout << "*y = " << *y << std::endl;
	std::cout << "y + 15 = " << y + 15 << std::endl;
	std::cout << "*y + 15 = " << *y + 15 << std::endl;

	return 0;
}