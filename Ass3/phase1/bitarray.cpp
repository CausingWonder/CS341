// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include "bitarray.h"


// Constructors
BitArray::BitArray(int size)
{
	BYTES = ((size + 7) / BIT_IN_BYTE);
	LENGTH = BYTES * BIT_IN_BYTE;

	data_ = new char[BYTES];
}

BitArray::BitArray(const BitArray& array)
{
	BYTES = array.BYTES;
	LENGTH = array.LENGTH;
	
	data_ = new char[array.LENGTH];
}

BitArray::~BitArray()
{
	delete[] data_;
}


/*
void BitArray::clear()
{

}

void BitArray::initialize(char* word, int size)
{
	BYTES = ((size + 7) / BIT_IN_BYTE);
	LENGTH = BYTES * BIT_IN_BYTE;

	delete[] data_;
	data_ = new char[BYTES];
}
*/


//
// void print()
//
void BitArray::print()
{	
	std::cout << "|";
	
	for (int i=0; i < BYTES; i++)
	{
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	
	std::cout << std::endl;	
}



bool BitArray::get(int position) const
{
	if (position >= LENGTH)
	{
		std::cout << "ERROR:BitArray.get:position>=LENGTH" << std::endl;
		return false;
	}
	else
	{
		unsigned int index_bit = position % BIT_IN_BYTE;
		unsigned int index_byte = position / BIT_IN_BYTE;
		unsigned int one = 128;

		return (data_[index_byte] & (one >> index_bit)) !=0;
	}

/*	unsigned int value_byte(0);
	unsigned int index_byte(0);
	unsigned int index_bit(0);
	unsigned int compare(0);

	index_byte = position / BIT_IN_BYTE;
	index_bit = position % BIT_IN_BYTE;
	value_byte = data_[index_byte];
	std::cout << "valByte " << &value_byte << std::endl;
	compare = 1;

	compare = compare << index_bit;
	compare = value_byte && compare;

	return (value_byte == compare ? false : true);*/
}
/*
bool BitArray::set(int position, int bit = 1)
{
	return false;
}

bool BitArray::flip(int position)
{
	return false;
}

void BitArray::complement()
{

}

char BitArray::get8(int position) const
{
	return '0';
}

void BitArray::set8(char c, int index)
{

}*/