


#include "bitarray.h"

int main()
{
	// Check constructor
	BitArray* array = new BitArray(32);

	std::cout << "***array***" << std::endl;
	std::cout << "BYTES:	" << array->bytes() << std::endl;
	std::cout << "LENGTH:	" << array->length() << std::endl;
	array->print();

	// Check initialize
	std::cout << "***initialize***" << std::endl;
	char josh[4] = {'j', 'o', 's', 'h'};
	array->initialize(josh, 4);
	array->print();

	// Check copy constructor
	BitArray* arrayCopy = new BitArray(*array);
	
	std::cout << "***arrayCopy***" << std::endl;
	std::cout << "BYTES:	" << arrayCopy->bytes() << std::endl;
	std::cout << "LENGTH:	" << arrayCopy->length() << std::endl;
	arrayCopy->print();

	// Clear array
	std::cout << "***clear***" << std::endl;
	array->print();
	array->clear();
	array->print();
	
	// Check get
	std::cout << "***get***" << std::endl;
	arrayCopy->print();
	std::cout << "|";
	for (int i=1; i<=arrayCopy->length(); i++)
	{
		std::cout << arrayCopy->get(i-1) << (i%8==0 ? "|" : "" );
	}
	std::cout << std::endl;
	std::cout << "3rd bit:		"<< arrayCopy->get(3) << std::endl;
	std::cout << "15th bit:		"<< arrayCopy->get(15) << std::endl;
	std::cout << "16th bit:		"<< arrayCopy->get(16) << std::endl;

	// Check flip
	std::cout << "***flip***" << std::endl;
	arrayCopy->flip(3);
	std::cout << "3rd bit flipped:	"<< arrayCopy->get(3) << std::endl;
	arrayCopy->flip(15);
	std::cout << "15th bit flipped:	"<< arrayCopy->get(15) << std::endl;
	arrayCopy->flip(16);
	std::cout << "16th bit flipped:	"<< arrayCopy->get(16) << std::endl;

	// Check set
	std::cout << "***set***" << std::endl;
	arrayCopy->set(3, 1);
	std::cout << "3rd bit set(1):		"<< arrayCopy->get(3) << std::endl;
	arrayCopy->set(3, 0);
	std::cout << "3rd bit set(0):		"<< arrayCopy->get(3) << std::endl;
	arrayCopy->set(15, 1);
	std::cout << "15th bit set(1):	"<< arrayCopy->get(15) << std::endl;
	arrayCopy->set(16, 0);
	std::cout << "16th bit set(0):	"<< arrayCopy->get(16) << std::endl;
	arrayCopy->set(16, 0);
	std::cout << "16th bit set(0):	"<< arrayCopy->get(16) << std::endl;

	// Check get8
	std::cout << "***get8***" << std::endl;
	arrayCopy->print();
	for (int i=0; i<arrayCopy->bytes(); i++)
	{
		std::cout << arrayCopy->get8(i);
	}
	std::cout << std::endl;

	// Check complement
	std::cout << "***complement***" << std::endl;
	arrayCopy->complement();
	arrayCopy->print();

	delete array;
	delete arrayCopy;

	return 0;
}