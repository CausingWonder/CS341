// Copy Constructor Example - Lecture #9
//
// By: Dr. Ryan Rybarczyk

#include <iostream>
#include "Deck.h"

int main()
{
	Deck d1;
	Deck d2(d1);
	
	// Testing time...

	d1.printDeck();

	std::cout << std::endl << std::endl;

	d2.printDeck();	
	
	return 0;
}