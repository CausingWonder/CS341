// Copy Constructor Example - Lecture #9
//
// By: Dr. Ryan Rybarczyk
#include "Deck.h"

// Creation    // Initialization
Deck::Deck() : deck_(nullptr)
{
	size_ = DEFAULT_SIZE;
	deck_ = new int[size_];
	
	for (int i=0; i < size_; i++)
	{
		deck_[i] = i;
	}
}
							    
Deck::Deck(const Deck & deck) : deck_(new int[deck.size_]), size_(deck.size_)
{
	// Shallow Copy
	//deck_ = deck.deck_;
	
	// Deep Copy
	for(int i=0; i < deck.size_; i++)
	{
		deck_[i] = deck.deck_[i];
		//deck.deck_[i] = 5;
		//deck.size_ = 5;
	}
}

// Destruction
Deck::~Deck()
{
	delete [] deck_;
}

void Deck::printDeck()
{
	for (int i=0; i < size_; i++)
	{
		std::cout << deck_[i] << std::endl;
	}
}