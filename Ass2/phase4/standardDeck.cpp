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
	numCards_ = 0;
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
		std::cout << "ERROR-StandardDeck::displayCard: " << i << std::endl;
	}
}

void StandardDeck::printDeck()
{
	if (isEmpty())
	{
		std::cout << "ERROR-StandardDeck::printDeck: isEmpty" << std::endl;
		return;
	}
	for (int i = 0; i < numCards_; i++)
	{
		std::cout << deck_[i].print() << std::endl;
	}
}

bool StandardDeck::addCard(Card c)
{
	// Checks if there is space in the deck
	if (numCards_ < DECK_SIZE && numCards_ >= 0)
	{
		deck_[numCards_] = c;
		numCards_++;
		return true;
	}
	else
	{
		return false; // The deck is full
	}
}

void StandardDeck::shuffle()
{
	if (isEmpty())
	{
		std::cout << "ERROR-StandardDeck::shuffle: isEmpty" << std::endl;
		return;
	}
	else if (numCards_ == 1)
	{
		std::cout << "ERROR-StandardDeck::shuffle: numCards_==1" << std::endl;
		return;
	} 
	else 
	{
		Card temp;

		for (int i = 0; i < numCards_ * 3; i++)
		{
			// Finds 2 random positions in the deck
			int card_position1 = rand() % numCards_;
			int card_position2 = rand() % numCards_;

			while (card_position1 == card_position2)
			{
				card_position2 = rand() % numCards_;
			} 
			
			// Swaps the 2 cards in the deck
			temp = deck_[card_position1];
			deck_[card_position1] = deck_[card_position2];
			deck_[card_position2] = temp;
		}
	}
}

bool StandardDeck::mergeDecks(StandardDeck& inputDeck, bool shuffle_mergedDeck)
{
	// Merges the inputDeck into the thisDeck.
	if (inputDeck.getNumCards() > 0 && addCard(inputDeck.deck_[inputDeck.getNumCards()-1]))
	{
		inputDeck.numCards_--;
		return mergeDecks(inputDeck, shuffle_mergedDeck); 
	}
	else 
	{
		// Shuffle the new deck if specified
		if (shuffle_mergedDeck)
		{
			shuffle();
		} else {}

		if (inputDeck.getNumCards() == 0)
		{
			return true; // inputDeck is empty, thisDeck may have space
		}
		else 
		{
			return false; // thisDeck is full, some cards were not merged
		}
	}
	
}

void StandardDeck::initializeDeck()
{
	// Initialize the deck with 52 cards
	for (int indexSuit = 1; indexSuit <= 4; indexSuit++)
	{
		for (int indexFace = 1; indexFace <= 13; indexFace++)
		{
			deck_[(indexSuit-1)*13+(indexFace-1)].initialize(indexSuit, indexFace);
			numCards_++;
		}
	}
} 

Card StandardDeck::dealCard()
{
	if (isEmpty())
	{
		std::cout << "WARNING-StandardDeck::dealCard: isEmpty" << std::endl;
		return Card(); // Return a default card
	}
	else 
	{
		numCards_--;
		Card topCard = deck_[numCards_];
		return topCard;
	}
}