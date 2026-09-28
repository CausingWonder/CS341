// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	public:
		Node();
		Node(int);
		~Node();

		int getData();
		
		void setValue(int);

		/**
		 * Comparison operator overload for comparing two Nodes
		 *
		 * @param[in]      other
		 * 
		 * @return          True if equal, false otherwise
		 */		
		bool operator==(const Node&) const;
		
		/**
		 * Less then operator overload for comparing two Nodes
		 *
		 * @param[in]      other
		 * 
		 * @return          True if less then other, false otherwise
		 */		
		bool operator<(const Node&) const;
		
		/**
		 * Greater then operator overload for comparing two Nodes
		 *
		 * @param[in]      other
		 * 
		 * @return          True if greater then other, false otherwise
		 */		
		bool operator>(const Node&) const;
	
	private:
		int data_;
};

#endif