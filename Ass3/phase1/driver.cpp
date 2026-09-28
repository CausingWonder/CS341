// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include "bitarray.h"

int main()
{
	BitArray* array = new BitArray(32);

	std::cout << "***array***" << std::endl;
	std::cout << "BYTES: " << array->bytes() << std::endl;
	std::cout << "LENGTH: " << array->length() << std::endl;
	array->print();

	std::cout << "|";
	for (int i=1; i<=32; i++)
	{
		std::cout << array->get(i-1) << (i%8==0 ? "|" : "" );
	}
	std::cout << std::endl;

	std::cout << std::endl;


	BitArray* arrayCopy = new BitArray(*array);

	std::cout << "***arrayCopy***" << std::endl;
	std::cout << "BYTES: " << arrayCopy->bytes() << std::endl;
	std::cout << "LENGTH: " << arrayCopy->length() << std::endl;
	arrayCopy->print();

	std::cout << "|";
	for (int i=1; i<=32; i++)
	{
		std::cout << arrayCopy->get(i-1) << (i%8==0 ? "|" : "" );
	}
	std::cout << std::endl;

	delete array;
	delete arrayCopy;

	return 0;
}