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
	StandardDeck* firstDeck = new StandardDeck();
	firstDeck->initializeDeck();

	// Print the deck
	firstDeck->printDeck();

	// Print additional information
	std::cout << "Is the deck empty? " << (firstDeck->isEmpty() ? "Yes" : "No") << std::endl;

	std::cout << "Number of cards: " << firstDeck->getNumCards() << std::endl;
	
	std::cout << "15th card: ";
	firstDeck->displayCard(15);

	// Shuffle the deck
	firstDeck->shuffle();
	std::cout << "Shuffled deck: " << std::endl;
	firstDeck->printDeck();

	// Merge w/ shuffle, thisDeck is full, inputDeck has cards
	StandardDeck* secondDeck = new StandardDeck();
	bool cardAdded = secondDeck->addCard(Card(1, 1)); // Ace of Spades
	cardAdded = secondDeck->addCard(Card(2, 13)); // King of Diamonds

	std::cout << "firstDeck size: " << firstDeck->getNumCards() << std::endl;
	std::cout << "secondDeck size: " << secondDeck->getNumCards() << std::endl;

	bool inputDeck_empty = secondDeck->mergeDecks(*firstDeck, true);
	std::cout << "inputDeck_empty: " << (inputDeck_empty ? "Yes" : "No") << std::endl;

	std::cout << "leftOverDeck (firstDeck) size: " << firstDeck->getNumCards() << std::endl;
	std::cout << "mergedDeck (secondDeck) size: " << secondDeck->getNumCards() << std::endl;

	std::cout << "leftOverDeck: " << std::endl;
	firstDeck->printDeck();
	std::cout << "mergedDeck: " << std::endl;
	secondDeck->printDeck();

	// Merge w/o shuffle, thisDeck has space, inputDeck is empty
	StandardDeck* thirdDeck = new StandardDeck();
	cardAdded = thirdDeck->addCard(Card(1, 1)); // Ace of Spades
	cardAdded = thirdDeck->addCard(Card(2, 13)); // King of Diamonds

	inputDeck_empty = thirdDeck->mergeDecks(*firstDeck, false);
	std::cout << "inputDeck_empty: " << (inputDeck_empty ? "Yes" : "No") << std::endl;
	
	std::cout << "leftOverDeck (firstDeck) size: " << firstDeck->getNumCards() << std::endl;
	std::cout << "mergedDeck (thirdDeck) size: " << thirdDeck->getNumCards() << std::endl;
	
	std::cout << "leftOverDeck: " << std::endl;
	firstDeck->printDeck();
	std::cout << "mergedDeck: " << std::endl;
	thirdDeck->printDeck();

	// Free heap memory
	delete firstDeck; 
	delete secondDeck;
	delete thirdDeck;

	return 0;
}

