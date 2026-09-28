#ifndef CARD_H
#define CARD_H

#include <string>

/**
 * @class Card
 *
 * The Card class is an object that represents a single card in from a standard deck of cards.
 * 
 * It is mainly used to store and print the contents of a card. It also allows you to initialize in two ways:
 * 		1) Via the initialize method (that sets both values at once). 
 * 		2) Via a non-default constructor, if you happen to want to do it when you declare a Card instance.
 */
class Card {        
	public:
		/// Default constructor.
		Card();	

		/**
		 * Initializing constructor.
		 *
		 * @param[in]      	Suit
		 * @param[in]		Face
		 */		
		Card(int, int);

		/**
		 * Copy constructor.
		 *
		 * @param[in] other
		 */		
		Card(const Card&);
		
		/// Destructor
		~Card();	
    	
		/**
		 * Returns the string corresponding to the suit of the card
		 *
		 * @return          Suit
		*/  
		std::string getSuit() const;	
		
		/**
	     * Returns the string corresponding to the face of the card
	     *
	     * @return          Face
	    */ 
		std::string getFace() const;		

		/**
		 * Returns the integer corresponding to the face of the card
		 *
		 * @return          FaceNum
		*/ 
		int getFaceVal() const;
        
		/**
		    * Initializes the Card with a Suit and Face value.
		    *
		 * @param[in]      Suit
		    * @param[in]	   Face
		   */
		void initialize(int, int);
		
		/**
	     * Returns a string with the full name of the card. (e.g., "Ace of Spades")
	     *
	     * @return          String
	    */ 
		std::string print() const;

		/**
		 * Comparison operator overload for comparing two Cards
		 *
		 * @param[in]      other
		 * 
		 * @return          True if equal, false otherwise
		 */		
		bool operator==(const Card&) const;
		
		/**
		 * Less then operator overload for comparing two Cards
		 *
		 * @param[in]      other
		 * 
		 * @return          True if less then other, false otherwise
		 */		
		bool operator<(const Card&) const;
		
		/**
		 * Greater then operator overload for comparing two Cards
		 *
		 * @param[in]      other
		 * 
		 * @return          True if greater then other, false otherwise
		 */		
		bool operator>(const Card&) const;
		
	private:
		int suitVal_;				 // Index of the Suit array that corresponds to the Suit of the Card.
		int faceVal_;				 // Index of the Face array that corresponds to the Face of the Card.
		static std::string SUIT[5];  // Static array of Suit values.
		static std::string FACE[14]; // Static array of Face values.
};

#endif