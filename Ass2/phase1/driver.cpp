// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include <iostream>

#include "card.h"

int main() {
	// The array of card instances on the heap
	Card* stdDeck = new Card[52];

	// Nested for loop to initialize the deck
	for (int indexSuit = 1; indexSuit <= 4; indexSuit++)
	{
		for (int indexFace = 1; indexFace <= 13; indexFace++)
		{
			stdDeck[(indexSuit-1)*13+(indexFace-1)].initialize(indexSuit, indexFace);
		}
	}

	// Print the deck
	for (int i = 0; i < 52; i++)
	{
		std::cout << stdDeck[i].print() << std::endl;
	}

	// Free heap memory
	for (int i = 0; i < 52; i++)
	{
		stdDeck[i].~Card();
	}

	return 0;
}

