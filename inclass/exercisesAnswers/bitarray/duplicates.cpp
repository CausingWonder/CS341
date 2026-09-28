// In-Class Exercise Solution - 10/8/2025
//
// By: Dr. Ryan Rybarczyk

#include <iostream>
#include <vector>
#include <string>
#include <bitset>

// Function to find and store duplicate letters.
std::vector<char> duplicatesList(std::string str);

int main()
{
	// Using a vector data structure to store our duplicate letters.
	std::vector<char> duplicates;
	
	std::string test = "butler bulldogs";
	
	duplicates = duplicatesList(test);
	
	std::cout << "Duplicate Letters: ";
	
	// For-Each Loop
	for(char letter : duplicates)
	{
		std::cout << letter << " ";
	}
	
	std::cout << std::endl;
	
	return 0;
}

std::vector<char> duplicatesList(std::string str)
{
	// Using an INT bit vector...I am so wasteful!
	// Exercise - do this with a character variable instead!
	int bitVector(0);
	
	// A vector data structure of type character.
	std::vector<char> duplicates;
	
	for (int i = 0; i < str.length(); ++i)
	{
		// Note: I am reading right to left as in binary and am using a signed
		//		 integer so the leading '1' will be present.
		int charIndex = str[i] - 'a';
		
		// If the bit is set then we have a duplicate...
		if ((bitVector & (1 << charIndex)) > 0)
		{
			// Similar to Java's append on an ArrayList...
			duplicates.push_back(str[i]);
		}
		
		bitVector |= (1 << charIndex);
	}
	
	// Display the Bit Vector...need 32 bits (4 bytes) to show all letters + space.
	std::cout << "Bit Vector: " << std::bitset<32>(bitVector) << std::endl;
	
	return duplicates;	
}