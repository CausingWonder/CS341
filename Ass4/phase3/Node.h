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

		int getValue();
		
		void setValue(int);
	
	private:
		int data_;
};

#endif