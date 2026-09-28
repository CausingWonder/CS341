// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
//
// Jrouse

#include "DawgHop.h"

#define DEBUG_DH false
#if DEBUG_DH == true
#ifndef LOCATION_DEBUG 
#define LOG std::cout << "    " << __PRETTY_FUNCTION__ << "    " << std::endl;
#endif
#else 
#define LOG ;
#endif

/// Public:
// Main Methods
void DawgHop::insertionSort(DoublyLinkedList* dll, int& dawgHop)
{LOG
	insertionSortHelper(dll->getTail(), dll, dawgHop);
}

/// Private:
// Recursive Helper Methods
void DawgHop::insertionSortHelper(LinkedNode* pivotNode, DoublyLinkedList* dll, int& dawgHop)
{LOG
	if (pivotNode != nullptr)
	{
		LinkedNode* oldPrevious = pivotNode->getPrevLinkedNode();
		shiftRight(pivotNode, dawgHop);
		insertionSortHelper(oldPrevious, dll, dawgHop);
	}
	else;
}

void DawgHop::shiftRight(LinkedNode* currentNode, int& dawgHop)
{LOG
	LinkedNode* nextNode = currentNode->getNextLinkedNode();
			
	if (nextNode != nullptr && currentNode->getValue() > nextNode->getValue())
	{
		swap(currentNode, nextNode);
		dawgHop++;
		shiftRight(nextNode, dawgHop);
	}
	else;
}

// Helper Methods
void DawgHop::swap(LinkedNode* node1, LinkedNode* node2)
{LOG
	Card temp = node1->getValue();
	node1->setValue(node2->getValue());
	node2->setValue(temp);
}