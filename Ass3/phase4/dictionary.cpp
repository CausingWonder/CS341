// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include "dictionary.h"

Dictionary::Dictionary() 
{
	data_ = BitArray();
	lookupTable_ = nullptr;
}

Dictionary::~Dictionary()
{
	delete[] lookupTable_;
}

Dictionary::Dictionary(const Dictionary& dict)
{
	if (dict.data_.length() > 0)
	{
		data_ = dict.data_;
		// !! LOOKUPTABLE
	}
	else
	{
		data_ = BitArray();
		// !! LOOKUPTABLE
	}
}

void Dictionary::initialize(char* word, int size)
{
	data_.initialize(word, size);
	// !! LOOKUPTABLE
}

int Dictionary::rank_range(int start, int end, int bit)
{
	int occurrence(0);
	
	for (int i=start; i<end; i++)
	{
		if (data_.get(i) == bit)
		{
			occurrence++;
		} else {}


		std::cout << data_.get(i) << ((i+1)%8==0 ? "|" : "" );
	}
	std::cout << std::endl;

	return occurrence;
}

int Dictionary::select_range(int start, int end, int k, int bit)
{
	unsigned int occurrence(0);
	
	for (int i=start; i<end; i++)
	{
		 if (data_.get(i) == bit)
		{
			occurrence++;
		} else {}

		std::cout << data_.get(i) << ((i+1)%8==0 ? "|" : "" );

		if (occurrence == k)
		{
			std::cout << std::endl;
			return i;
		} else {}
	}

	return 0;
}

int Dictionary::rank(int end, int bit)
{
	return rank_range(0, end, bit);
}

int Dictionary::select(int k, int bit)
{
	return select_range(0, data_.length(), k, bit);
}

/*void Dictionary::printLookupTable(std::ostream& output)
{

}*/