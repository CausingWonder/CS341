// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include "standardDeck.h"

StandardDeck::StandardDeck() 
{
	deck_ = new Card[DECK_SIZE];
	numCards_ = DECK_SIZE;

	// Nested for loop to initialize the deck
	for (int indexSuit = 1; indexSuit <= 4; indexSuit++)
	{
		for (int indexFace = 1; indexFace <= 13; indexFace++)
		{
			deck_[(indexSuit-1)*13+(indexFace-1)].initialize(indexSuit, indexFace);
		}
	}
}

StandardDeck::~StandardDeck() 
{
	delete[] deck_;
}

bool StandardDeck::isEmpty() 
{
	return (numCards_ == 0);
}

int StandardDeck::getNumCards() 
{
	return numCards_;
}	

void StandardDeck::displayCard(int i) 
{
	if (i>=0 && i<numCards_)
	{
		std::cout << deck_[i].print() << std::endl;
	}
	else
	{
		std::cout << "Invalid index " << i << std::endl;
	}
}

void StandardDeck::printDeck()
{
	for (int i = 0; i < numCards_; i++)
	{
		std::cout << deck_[i].print() << std::endl;
	}
}