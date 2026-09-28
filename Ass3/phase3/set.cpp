#include "set.h"

// Constructors
Set::Set(int size)
{
	data_ =  BitArray(size);	
}                         

Set::~Set() {}                               

void Set::initialize(char * word, int size)
{
	data_.initialize(word, size);
}

int Set::getCardinality() const
{
	int counter_ones(0);

	for (int i=0; i<data_.length(); i++)
	{
		if (data_.get(i))
		{
			counter_ones++;
		} else {}
	}

	return counter_ones;
}

BitArray& Set::getData()
{
	return data_;
}               

bool Set::setUnion(Set& B)
{
	if (data_.bytes() != B.getData().bytes()) 
	{
		std::cout << "ERROR:Set.setUnion:BYTES!=B.BYTES" << std::endl;
		return false;
	}
	else
	{
		for (int i=0; i<data_.bytes(); i++)
		{
			char in_union = (data_.get8(i) | B.getData().get8(i));
			data_.set8(in_union, i);
		}
		
		return true;
	}

	return false;
}

bool Set::setIntersection(Set& B)
{
	if (data_.bytes() != B.getData().bytes()) //Size compatibility
	{
		std::cout << "ERROR:Set.setUnion:BYTES!=B.BYTES" << std::endl;
		return false;
	}
	else
	{
		for (int i=0; i<data_.bytes(); i++)
		{
			char in_interset = (data_.get8(i) & B.getData().get8(i));
			data_.set8(in_interset, i);
		}

		return true;
	}

	return false;
}