#include <iostream>
#include <bitset>

int main() {

	int x(0), y(0), z(0);

	x = 15;
	y = 87;

	z = x ^ y;

	std::bitset<8> bitX = x;
	std::bitset<8> bitY = y;
	std::bitset<8> bitZ = z;

	std::cout << "x: " << bitZ << std::endl;
	std::cout << "y: " << bitZ << std::endl;
	std::cout << "&: " << bitZ << std::endl;

	char val(' ');
	val = 'z';
	std::bitset<8> bitVal = val;
	std::cout << "val: " << bitVal << std::endl;


	return 0;
}