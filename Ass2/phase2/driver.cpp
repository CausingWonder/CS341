// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include <iostream>

#include "card.h"
#include "standardDeck.h"

int main() {
	// The array of card instances on the heap
	StandardDeck* stdDeck = new StandardDeck();

	// Print the deck
	stdDeck->printDeck();

	// Print additional information
	std::cout << "Is the deck empty? " << (stdDeck->isEmpty() ? "Yes" : "No") << std::endl;

	std::cout << "Number of cards: " << stdDeck->getNumCards() << std::endl;
	
	std::cout << "15th card (0th starting): ";
	stdDeck->displayCard(15);

	// Free heap memory
	delete[] stdDeck; 

	return 0;
}

