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
	data_ = dict.data_;
	initialize_lookupTable();
}

void Dictionary::initialize(char* word, int size)
{
	data_.initialize(word, size);
	initialize_lookupTable();
}

int Dictionary::rank_range(int start, int end, int bit)
{
	int occurrence(0);
	int start_byte = start / BIT_IN_BYTE;
	int end_byte = start / BIT_IN_BYTE;
	int start_bit = start % BIT_IN_BYTE;
	int end_bit = start % BIT_IN_BYTE;
	
	// Range is less then a byte, can't use lookupTable
	if (start_byte == end_byte)
	{
		for (int i=start; i<end; i++)
		{
			if (data_.get(i) == bit) occurrence++;
		}
		return occurrence;
	}
	else
	{
		// Range starts in the middle of a byte
		if (start_bit != 0)
		{
			start_byte++; // Increments the start byte to the next byte
			
			for (int i=start; i<((start_byte)*BIT_IN_BYTE); i++)
			{
				if (data_.get(i) == bit) occurrence++;
			}
		} else {}

		// Range ends in the middle of a byte
		if (end_bit != 0)
		{
			for (int i=(end_byte*BIT_IN_BYTE); i<end; i++)
			{
				if (data_.get(i) == bit) occurrence++;
			}
		} else {}

		// Remanding range of full bytes will implement the lookupTable
		for (int i=start_byte; i<end_byte; i++)
		{
			unsigned char byte = (unsigned char)data_.get8(i);

			if (bit == 1)
			{
				occurrence += lookupTable_[i];
			}
			else
			{
				occurrence += (BIT_IN_BYTE - lookupTable_[i]);
			}
		}

		return occurrence;
	}

	std::cout << std::endl;

	return occurrence;
}

int Dictionary::select_range(int start, int end, int k, int bit)
{
	int occurrence(0);
	int start_byte = start / BIT_IN_BYTE;
	int end_byte = start / BIT_IN_BYTE;
	int start_bit = start % BIT_IN_BYTE;
	int end_bit = start % BIT_IN_BYTE;

	// Range is less then a byte, can't use lookupTable
	if (start_byte == end_byte)
	{
		for (int i=start; i<end; i++)
		{
			if (data_.get(i) == bit) occurrence++;
			if (occurrence == k) return i;
		}
	}
	else
	{
		// Range starts in the middle of a byte
		if (start_bit != 0)
		{
			start_byte++; // Increments the start byte to the first full byte
		
			for (int i=start; i<((start_byte)*BIT_IN_BYTE); i++)
			{
				if (data_.get(i) == bit) occurrence++;
				if (occurrence == k) return i;
			}
		} else {}

		// Remanding range of full bytes will implement the lookupTable
		for (int i=start_byte; i<end_byte; i++)
		{
			unsigned char byte = (unsigned char)data_.get8(i);
			int occurrence_inByte = (((bit == 1) ? 0 : BIT_IN_BYTE) - lookupTable_[byte]);
		
			// Check if kth occurrence is in byte
			if (occurrence + occurrence_inByte >= k)
			{
				for (int j=(i*BIT_IN_BYTE); j<((i+1)*BIT_IN_BYTE); j++)
				{
					if (data_.get(i) == bit) occurrence++;
					if (occurrence == k) return j;
				}
			}
		}

		// Range ends in the middle of a byte
		if (end_bit != 0)
		{
			for (int i=(end_byte*BIT_IN_BYTE); i<end; i++)
			{
				if (data_.get(i) == bit) occurrence++;
				if (occurrence == k) return i;
			}
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

void Dictionary::printLookupTable(std::ostream& output)
{
	for (int i=0; i<DICTIONARY_SIZE; i++)
	{
		output << "lookuptable_[" << i << "] = " << lookupTable_[i] << std::endl;
	}
}

void Dictionary::initialize_lookupTable()
{
	if (lookupTable_ == nullptr)
	{
		lookupTable_ = new int[DICTIONARY_SIZE];
		int count_ones(0);
		unsigned char byte(' ');
	
		for (unsigned i=0; i<DICTIONARY_SIZE; i++)
		{
			byte = (char)i;
			count_ones = 0;

			while (byte != 0)
			{
				count_ones += byte & 1;
				byte = byte >> 1;
			}

			lookupTable_[i] = count_ones;
		}
	} else {}
}