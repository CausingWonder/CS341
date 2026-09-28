// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on the StudentAdded portions
// of this assignment And have not manipulated the 
// code in any way that is not the StudentAdded portion.
//
// Jrouse

#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#include <iostream> // StudentAdded: Included for std::cout
#include "card.h"

#define DECK_SIZE 52

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck
{
	public:
		/// Default constructor.
		StandardDeck();
		
		//StandardDeck(const StandardDeck & sd); StudentAdded: Included for std::cout
		
		/// Default destructor.
		~StandardDeck();

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		bool isEmpty();	

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		int getNumCards();

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		void displayCard(int i);

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		void printDeck();	
		
		/**
		 * Will add Card c to the end of the deck if there is space.
		 * If Card c is added successfully, addCard returns true.
		 * If there is no space in the deck, addCard returns false.
		 * @param[in]       Card c
		 * @return          Boolean
		 */
		bool addCard(Card c); // StudentAdded: Phase3

		/**
		 * Shuffles the deck by randomly swapping 3 time size of deck.
		 */
		void shuffle(); // StudentAdded: Phase3

		/**
		 * Merges the input StandardDeck into the current StandardDeck.
		 * The bool parameter indicates whether to shuffle the new merged deck.
		 * Shuffle is set to false by default.
		 * If merged successfully returns true.
		 * @param[in]       StandardDeck &
		 * @param[in]       Boolean     
		 * @return          Boolean     
		 */
		bool mergeDecks(StandardDeck & input_stdDeck, bool shuffle_mergedDeck=false); // StudentAdded: Phase3

		/**
		 * Will create a StandardDeck array of 52 cards.
		 */
		void initializeDeck(); // StudentAdded: Phase3

	protected: 
		Card* deck_;	// Pointer to record the location of the array of Cards in memory.
		int numCards_;	// Stores the number of Cards currently in the deck.
};

#endif