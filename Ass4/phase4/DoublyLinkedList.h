// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "LinkedList.h"

class DoublyLinkedList : public LinkedList
{
	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		virtual void printList() override;
		virtual void insert(int) override;
};

#endif