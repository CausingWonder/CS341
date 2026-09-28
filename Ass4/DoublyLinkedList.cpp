// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
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

/// Public:
// Lifetime Methods
DoublyLinkedList::DoublyLinkedList() 
:LinkedList()
{LOG}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
:LinkedList(other)
{LOG}

DoublyLinkedList::~DoublyLinkedList()
{LOG}

// Class Operators
void DoublyLinkedList::insertLinkedNode(LinkedNode* prevNode, Card data)
{LOG
    LinkedNode* newNode = new LinkedNode(data);

    if (isEmpty()) //Empty
    {	
        setHead(newNode);
        setTail(newNode);
        length_--;
    }
    else if ((prevNode == nullptr) || (prevNode->getValue() == Card())) //Head Insertion
    {
		LinkedNode* oldHead = getHead();
		setHead(newNode);
		newNode->setNextLinkedNode(oldHead);
		oldHead->setPrevLinkedNode(newNode);
	}
	else if (getTail() == prevNode) //Tail Insertion
	{	
		setTail(newNode);
		prevNode->setNextLinkedNode(newNode);
		newNode->setPrevLinkedNode(prevNode);
	}
	else //Middle Insertion
	{	
		LinkedNode* nextNode = prevNode->getNextLinkedNode();
		newNode->setNextLinkedNode(nextNode);
		nextNode->setPrevLinkedNode(newNode);
		prevNode->setNextLinkedNode(newNode);
		newNode->setPrevLinkedNode(prevNode);
		length_++;
	}
}

void DoublyLinkedList::deleteNode(Card data)
{LOG
	LinkedNode* originalHead = getHead();

	if (originalHead != nullptr)
	{
		if (data == originalHead->getValue())
		{
			if (originalHead == getTail()) //Delete only node
			{
				delete originalHead;
				setHead(nullptr);
				setTail(nullptr);
				length_ = 0;
			}
			else //Delete head
			{
				LinkedNode* newHead = originalHead->getNextLinkedNode();
				LinkedNode* after_newHead = newHead->getNextLinkedNode();

				setHead(newHead);
				length_--;
				newHead->setNextLinkedNode(after_newHead);
				newHead->setPrevLinkedNode(nullptr);

				originalHead->setNextLinkedNode(nullptr);
				delete originalHead;

				length_--;
			} 
		} 
		else //Delete other node
		{
			LinkedNode* deleteNode = nullptr;
	
			while (originalHead->hasNextLinkedNode()) //Find node
			{
				if (originalHead->getNextLinkedNode()->getValue() == data)
				{	deleteNode = originalHead;}
				else;
	
				originalHead = originalHead->getNextLinkedNode();
			}
	
			if (deleteNode != nullptr)
			{	
				LinkedNode* nodeToBeDeleted = deleteNode->getNextLinkedNode();
				LinkedNode* nextNode = nodeToBeDeleted->getNextLinkedNode();
	
				if (nodeToBeDeleted == getTail())
				{
					setTail(deleteNode);
					length_--;
					deleteNode->setNextLinkedNode(nullptr);
				}
				else
				{
					deleteNode->setNextLinkedNode(nextNode);
					if (nextNode != nullptr)
					{	nextNode->setPrevLinkedNode(deleteNode);}
					else;
				}
				
				nodeToBeDeleted->setNextLinkedNode(nullptr);
				nodeToBeDeleted->setPrevLinkedNode(nullptr);
				delete nodeToBeDeleted;
				length_--;
			}
			else
			{	std::cout << "Element is not in list" << std::endl;}
		}
	}
	else
	{	std::cout << "List is empty" << std::endl;}
}

// Additional Methods
void DoublyLinkedList::printList() const
{LOG
	LinkedNode* currentNode = getHead();
	
	if (currentNode != nullptr)
	{
		while (currentNode->hasNextLinkedNode())
		{
			std::cout << currentNode->getValue().print() << " <--> ";
			currentNode = currentNode->getNextLinkedNode();
		}
	
		std::cout << currentNode->getValue().print() << std::endl;
	}
	else 
	{	std::cout << "List is empty!" << std::endl;}
}
