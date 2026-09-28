// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include "dictionary.h"


int main()
{
	void out(BitArray& array, bool print=1);

	BitArray* array = new BitArray();
	Dictionary dict;
	char test[4] = {'t', 'e', 's', 't'};

	array->initialize(test, 4);
	dict.initialize(test, 4);

	out(*array);
	std::cout << std::endl;


	std::cout << "***rank_range & rank***" << std::endl;
	int length_test = 4*BIT_IN_BYTE;
	int dict_rank, dict_select;

	dict_rank = dict.rank_range(15, 31, 1);
	std::cout << "dict.rank_range one: " << dict_rank << std::endl;
	dict_rank = dict.rank_range(15, 31, 0);
	std::cout << "dict.rank_range zero: " << dict_rank << std::endl;

	dict_rank = dict.rank(length_test, 1);
	std::cout << "dict.rank one: " << dict_rank << std::endl;
	dict_rank = dict.rank(length_test, 0);
	std::cout << "dict.rank zero: " << dict_rank << std::endl;

	std::cout << std::endl;
	std::cout << "***dict: rank & select***" << std::endl;

	dict_select = dict.select_range(0, 15, 2, 1);
	std::cout << "dict.select_range one: " << dict_select << std::endl;
	dict_select = dict.select_range(0, 15, 2, 0);
	std::cout << "dict.select_range zero: " << dict_select << std::endl;

	dict_select = dict.select(5, 1);
	std::cout << "dict.select one: " << dict_select << std::endl;
	dict_select = dict.select(5, 0);
	std::cout << "dict.select zero: " << dict_select << std::endl;

	std::cout << std::endl;
	std::cout << "***Printing lookup table***" << std::endl;
	dict.printLookupTable(std::cout);

	delete array;
};

void out(BitArray& array, bool print=1)
{
	if (print) array.print();
	
	for (int i=0; i<array.bytes(); i++)
	{
		std::cout << array.get8(i);
	}
	std::cout << std::endl;
};