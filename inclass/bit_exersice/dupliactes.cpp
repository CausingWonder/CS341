// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include "bitarray.h"

int main()
{
	// chars are prefixed 011 and suffixed is apart of the value. 
	// prefix00001 = a
	// prefix00010 = b
	// prefix00011 = c
	// prefix11010 = z
	// index of letters to numbers is useing a prefix of 000

	// is equal when post fix are equal
	unsigned int countChar_phrase(0);
	#define countChar_phrase 15

	char phrase[15];
	phrase = {'b','u','t','l','e','r',' ','b','u','l','l','d','o','g','s'};

	BitArray* array_phrase = new BitArray();

	array_phrase->initialize(phrase, countChar_phrase);

	bool found(0);
	bool lookingAt(0);
	bool found[BIT_IN_BYTE];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 3; j < 8; j++)
		{
			found = array_phrase->get(i*BIT_IN_BYTE+j);
		
			for (int k = 0; k < 15; k++)
			{
				found = {0,0,0,0,0,0,0,0};
				for (int l = 3; l < 8; l++)
				{
					lookingAt = array_phrase->get(i*BIT_IN_BYTE+j + (k*BIT_IN_BYTE+l));
					if (found != lookingAt)
					{
						l = 8;
						k = 15;
					} 
					else
					{
						found [l] = lookingAt;
					}
				}
				if (found == {0,0,0,0,0,0,0,0})
				{
					std::cout << found/*for look to print all*/<< std::endl;
				}
			}
		}
	}



	
	
	return 0;
}