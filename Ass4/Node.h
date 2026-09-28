// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#ifndef NODE_H
#define NODE_H

#include "Card.h"
#include <iostream>

class Node
{
	public:
		/// Defualt constructor
		Node();

		/**
		 * Initializing constructor.
		 *
		 * @param[in]      	data
		 */		
		Node(Card);

		/**
		 * Copy constructor.
		 *
		 * @param[in]		other
		 */		
		Node(const Node&);

		/// Destructor
		~Node();

		/**
		 * Returns the value of data, a Card
		 *
		 * @return 			data
		 */		
		Card getValue() const;
		

		/**
		 * Initializes the Node with a data value of type Card
		 *
		 * @param[in]      	Card
		 */		
		void setValue(Card);
	
	private:
		Card data_;
};

#endif