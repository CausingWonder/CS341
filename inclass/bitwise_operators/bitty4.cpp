#include <iostream>
#include <bitset>

int main() {

	unsigned int x(0), y(0), z(0);
	int count(0);

	x = 15; // x = 00001111

	y = 1; // y = 00000001, base bit array to use left and right shifts to find the bit at a set index in x(other variable)
	
	y = y << 3;
	z = x & y;
	
	std::cout << "4th Bit Set? " << (z > 0 ? "True" : "False") << std::endl;

	while (count < 5)
	{
		int position(0);
		std::cout << "Pls enter a position" << std::endl;
		std::cin >> position;

		y = 1; // y = 00000001, base bit array to use left and right shifts to find the bit at a set index in x(other variable)
		
		y = y << (7 - position);

		z = x & y;
		
		std::cout << position << " Bit Set? " << (z > 0 ? "True" : "False") << std::endl;

		// Then you can use or with y to set the bit you want using left and right shift

		count ++;
	}

	return 0;
}