#ifndef DECK_H
#define DECK_H

// Copy Constructor Example - Lecture #9
//
// By: Dr. Ryan Rybarczyk

#include <iostream>

#define DEFAULT_SIZE 52

class Deck
{
	public:
		Deck();
		// Copy Constructor
		Deck(const Deck & deck); // const -> to prevent any changes to deck
		~Deck();
		void printDeck();
	private:
		int * deck_;
		int size_;
};
#endif