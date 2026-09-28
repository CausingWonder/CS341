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
	BYTES = ((size + BIT_IN_BYTE - 1) / BIT_IN_BYTE);
	LENGTH = BYTES * BIT_IN_BYTE;

	if (size > 0)
	{
		data_ = new char[BYTES];
		clear();
	}
	else
	{
		data_ = nullptr;
	}
}

BitArray::BitArray(const BitArray& array)
{
	BYTES = array.BYTES;
	LENGTH = array.LENGTH;
	
	if (LENGTH > 0)
	{
		data_ = new char[BYTES];
		for (int i=0; i<BYTES; i++)
		{
			data_[i] = array.data_[i];
		}
	}
	else
	{
		data_ = nullptr;
	}
}

BitArray::~BitArray()
{
	delete[] data_;
}

void BitArray::clear()
{
	for (int i=0; i<bytes(); i++)
	{
		data_[i] = 0;
	}
}

void BitArray::initialize(char* word, int size)
{
	BYTES = size;
	LENGTH = BYTES * BIT_IN_BYTE;

	delete[] data_;
	
	if (size > 0)
	{
		data_ = new char[BYTES];
		for (int i=0; i<BYTES; i++)
		{
			data_[i] = word[i];
		}
	}
	else
	{
		data_ = nullptr;
	}
}

void BitArray::print()
{	
	std::cout << "|";
	
	for (int i=0; i < bytes(); i++)
	{
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	
	std::cout << std::endl;	
}

bool BitArray::get(int position) const
{
	if (position >= length())
	{
		std::cout << "ERROR:BitArray.get:position>=LENGTH" << std::endl;
		return false;
	}
	else
	{
		unsigned int index_bit = position % BIT_IN_BYTE;
		unsigned int index_byte = position / BIT_IN_BYTE;

		return (data_[index_byte] & (128 >> index_bit)) != 0;
	}
}

bool BitArray::set(int position, int bit)
{
	if (position >= length())
	{
		std::cout << "ERROR:BitArray.set:position>=LENGTH" << std::endl;
		return false;
	}
	else
	{
		unsigned int index_bit = position % BIT_IN_BYTE;
		unsigned int index_byte = position / BIT_IN_BYTE;

		if (bit == 1)
		{
			// Set bit to 1
			data_[index_byte] = data_[index_byte] | (128 >> index_bit);
		}
		else
		{
			// Set bit to 0
			data_[index_byte] = data_[index_byte] & ~(128 >> index_bit);
		}
	
		return true;
	}
	return false;
}

bool BitArray::flip(int position)
{
	if (position >= length())
	{
		std::cout << "ERROR:BitArray.flip:position>=LENGTH" << std::endl;
		return false;
	}
	else
	{
		unsigned int index_bit = position % BIT_IN_BYTE;
		unsigned int index_byte = position / BIT_IN_BYTE;

		data_[index_byte] = data_[index_byte] ^ (128 >> index_bit);

		return true;
	}
	return false;
}

void BitArray::complement()
{
	for (int i=0; i<bytes(); i++)
	{
		data_[i] = ~data_[i];
	}
}

char BitArray::get8(int position) const
{
	if (position >= bytes())
	{
		std::cout << "ERROR:BitArray.get8:position>=LENGTH" << std::endl;
		return 0;
	}
	else
	{
		return data_[position];
	}
}

void BitArray::set8(char c, int index)
{

}