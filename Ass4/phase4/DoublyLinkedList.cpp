// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "DoublyLinkedList.h"

#define DEBUG_DLL false
#if DEBUG_DLL == true
#ifndef LOCATION_DEBUG 
#define LOG std::cout << "    " << __PRETTY_FUNCTION__ << "    " << std::endl;
#endif
#else 
#define LOG ;
#endif

DoublyLinkedList::DoublyLinkedList() : LinkedList()
{LOG
}

DoublyLinkedList::~DoublyLinkedList()
{LOG
}

void DoublyLinkedList::printList()
{LOG
	LinkedNode* currentNode = getHead();
	
	if (currentNode != nullptr)
	{
		while (currentNode->hasNextLinkedNode())
		{
			std::cout << currentNode->getValue() << " <--> ";
			currentNode = currentNode->getNextLinkedNode();
		}
	
		std::cout << currentNode->getValue() << std::endl;
	}
	else 
	{	std::cout << "List is empty!" << std::endl;}
}

void DoublyLinkedList::insert(int data)
{LOG
	LinkedNode* newNode = new LinkedNode(data);
	    
	if (getHead() == nullptr) 
		{   
			setHead(newNode);
		}
		else 
		{
			LinkedNode* tail = getTail();
			tail->setNextLinkedNode(newNode);
			newNode->setPrevLinkedNode(tail);
			setTail(newNode);
		}
}

