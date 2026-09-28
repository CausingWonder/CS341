


#include "set.h"

int main()
{
	std::cout << "***set8***" << std::endl;	
	BitArray* array = new BitArray();
	array->print();

	char josh[4] = {'j', 'o', 's', 'h'};
	array->initialize(josh, 4);
	array->print();
	for (int i=0; i<array->bytes(); i++)
	{
		std::cout << array->get8(i);
	}
	std::cout << std::endl;

	array->set8('p', 0);
	array->print();
	for (int i=0; i<array->bytes(); i++)
	{
		std::cout << array->get8(i);
	}
	std::cout << std::endl;

	array->set8('t', array->bytes()-1);
	array->print();
	for (int i=0; i<array->bytes(); i++)
	{
		std::cout << array->get8(i);
	}
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "***Set construct & initialize***" << std::endl;
	Set set;
	char sets[4] = {'s', 'e', 't', 's'};
	set.initialize(sets, 4);
	BitArray* array2 = new BitArray(set.getData());
	array2->print();

	std::cout << std::endl;
	std::cout << "***getCardinality***" << std::endl;
	std::cout << "Cardinality: " << set.getCardinality() << std::endl;

	std::cout << std::endl;
	std::cout << "***union***	josh U sets" << std::endl;
	Set set2;
	set2.initialize(josh, 4);

	array->initialize(josh, 4);
	for (int i=0; i<array->bytes(); i++)
	{
		std::cout << array->get8(i);
	}
	array->print();

	for (int i=0; i<array2->bytes(); i++)
	{
		std::cout << array2->get8(i);
	}
	array2->print();

	set.setUnion(set2);
	delete array2;
	array2 = new BitArray(set.getData());

	for (int i=0; i<array2->bytes(); i++)
	{
		std::cout << array2->get8(i);
	}
	array2->print();

	std::cout << std::endl;
	std::cout << "***intersection***	josh X sets" << std::endl;
	for (int i=0; i<array->bytes(); i++)
	{
		std::cout << array->get8(i);
	}
	array->print();
	
	set.initialize(sets, 4);
	delete array2;
	array2 = new BitArray(set.getData());
	for (int i=0; i<array2->bytes(); i++)
	{
		std::cout << array2->get8(i);
	}
	array2->print();
	
	set.setIntersection(set2);
	delete array2;
	array2 = new BitArray(set.getData());
	
	for (int i=0; i<array2->bytes(); i++)
	{
		std::cout << array2->get8(i);
	}
	array2->print();

	delete array;
	delete array2;
	return 0;
}