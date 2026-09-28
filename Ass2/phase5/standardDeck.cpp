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
	// Check deck bounds
	if (numCards_ >= DECK_SIZE)
	{
		std::cout << "ERROR-StandardDeck::addCard: Deck is full" << std::endl;
		return false;
	}

	// Check for invalid state
	if (numCards_ < 0)
	{
		std::cout << "ERROR-StandardDeck::addCard: Invalid numCards_" << std::endl;
		return false;
	}

	// Add the card
	deck_[numCards_] = c;
	numCards_++;
	return true;
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
	// Early validation
	if (inputDeck.getNumCards() < 0)
	{
		std::cout << "ERROR-StandardDeck::mergeDecks: Invalid input deck card count" << std::endl;
		return false;
	}

	if (numCards_ < 0)
	{
		std::cout << "ERROR-StandardDeck::mergeDecks: Invalid this deck card count" << std::endl;
		return false;
	}

	// Check if merging would exceed deck size
	if (numCards_ + inputDeck.getNumCards() > DECK_SIZE)
	{
		std::cout << "ERROR-StandardDeck::mergeDecks: Merged deck would exceed maximum size" << std::endl;
		return false;
	}

	// Merges the inputDeck into the thisDeck
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
		}

		// Return success only if all cards were merged
		return (inputDeck.getNumCards() == 0);
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

	if (numCards_ > DECK_SIZE)
	{
		std::cout << "ERROR-StandardDeck::dealCard: numCards_ > DECK_SIZE" << std::endl;
		return Card();
	}

	numCards_--;
	Card topCard = deck_[numCards_];
	return topCard;
}