// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedNode.h"

class LinkedList
{
	public:
		LinkedList();
		//ADD COPY CONSTRUCTOR
		~LinkedList();

		void printList();
		bool isEmpty();
		void insert(int);
		void deleteNode(int);

		int getLength();
		LinkedNode * getTail();
		LinkedNode * getHead();
		
		void setTail(LinkedNode*);
		void setHead(LinkedNode*);

	private:
		LinkedNode* head_;
		LinkedNode* tail_;
		int length_;
		
		void insertLinkedNode(LinkedNode*, int);
};

#endif