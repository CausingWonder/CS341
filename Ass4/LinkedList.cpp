// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "LinkedList.h"

#define DEBUG_LL false
#if DEBUG_LL == true
#ifndef LOCATION_DEBUG 
#define LOG std::cout << "    " << __PRETTY_FUNCTION__ << "    " << std::endl;
#endif
#else 
#define LOG ;
#endif

/// Public:
// Lifetime Methods
LinkedList::LinkedList() 
:head_(nullptr), tail_(nullptr), length_(0)
{LOG}

LinkedList::LinkedList(const LinkedList&)
{LOG
	LinkedNode* currentNode = head_;

	while (currentNode != nullptr)
	{
		insert(currentNode->getValue());
		currentNode = currentNode->getNextLinkedNode();
	}
}

LinkedList::~LinkedList()
{LOG
	while (head_ != nullptr) 
	{	
		LinkedNode* oldHead = head_;
		head_ = head_->getNextLinkedNode();

		oldHead->setNextLinkedNode(nullptr);
		oldHead->setPrevLinkedNode(nullptr);
		delete oldHead;
	} 
	tail_ = nullptr;
}

// Getters
LinkedNode* LinkedList::getHead() const
{LOG
	return head_;
}

LinkedNode* LinkedList::getTail() const
{LOG
	return tail_;
}

int LinkedList::getLength() const
{LOG
	return length_;
}

// Setters
void LinkedList::setHead(LinkedNode* head)
{LOG
	if (head_ == nullptr)
	{	
		head_ = head;
		tail_ = head;
	} 
	else if (head == nullptr)
	{
		head_ = nullptr;
	}
	else
	{
		head->setNextLinkedNode(head_);
		head_ = head;
	}
	length_++;
}

void LinkedList::setTail(LinkedNode* tail)
{LOG
	if (tail_ == nullptr)
	{	
		head_ = tail;
		tail_ = tail;
	} 
	else if (tail == nullptr)
	{
		tail_ = nullptr;
	}
	else
	{	
		tail_->setNextLinkedNode(tail);
		tail_ = tail;
	}
	length_++;
}

// Class Operators
void LinkedList::insert(Card data)
{LOG
	insertLinkedNode(tail_, data);
}

void LinkedList::deleteNode(Card data)
{LOG
	if (head_ != nullptr)
	{
		if (data == head_->getValue())
		{
			if (head_ == tail_) // Case 1
			{
				delete head_;
				head_ = nullptr;
				tail_ = nullptr;
			}
			else // Case 2
			{
				LinkedNode* newHead = nullptr;

				newHead = head_->getNextLinkedNode();
				head_->setNextLinkedNode(nullptr);
				delete head_;

				head_ = newHead;
			} 
		} 
		else // case3
		{
			LinkedNode* node = head_;
			LinkedNode* deleteNode = nullptr;

			while (node->hasNextLinkedNode())
			{
				if (node->getNextLinkedNode()->getValue() == data)
				{	deleteNode = node;}
				else;

				node = node->getNextLinkedNode();
			}

			if (deleteNode != nullptr)
			{	
				LinkedNode* nodeToBeDeleted = deleteNode->getNextLinkedNode();

				deleteNode->setNextLinkedNode(nodeToBeDeleted->getNextLinkedNode());
				
				nodeToBeDeleted->setNextLinkedNode(nullptr);

				if (nodeToBeDeleted == tail_)
				{	tail_ = deleteNode;}
				else;

				delete nodeToBeDeleted;
			}
			else
			{	std::cout << "Element is not in list" << std::endl;}
		}
		length_--;
	}
	else
	{	std::cout << "head_ points to nullptr" << std::endl;}
}

// Additional Methods
void LinkedList::printList() const
{LOG
	LinkedNode* currentNode = head_;
	
	if (currentNode != nullptr)
	{
		while (currentNode->hasNextLinkedNode())
		{
			std::cout << currentNode->getValue().print() << " -> ";
			currentNode = currentNode->getNextLinkedNode();
		}
	
		std::cout << currentNode->getValue().print() << std::endl;
	}
	else 
	{	std::cout << "List is empty!" << std::endl;}
}

bool LinkedList::isEmpty()
{LOG
	return (length_ == 0);	
}

/// Protected:
// Helper Methods
void LinkedList::insertLinkedNode(LinkedNode* prevNode, Card data)
{LOG
	LinkedNode* newNode = new LinkedNode(data);

	if (isEmpty()) //Empty
	{	head_ = newNode;
		tail_ = newNode;
	}
	else //Next Insertion
	{	
		if (tail_ == prevNode)
		{	tail_ = newNode;}
		else
		{	newNode->setNextLinkedNode(prevNode->getNextLinkedNode());}

		prevNode->setNextLinkedNode(newNode);
	}

	length_++;
}