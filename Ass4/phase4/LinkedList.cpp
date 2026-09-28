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

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr), length_(0)
{LOG
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

// Methods
void LinkedList::printList()
{LOG
	LinkedNode* currentNode = head_;
	
	if (currentNode != nullptr)
	{
		while (currentNode->hasNextLinkedNode())
		{
			std::cout << currentNode->getValue() << " -> ";
			currentNode = currentNode->getNextLinkedNode();
		}
	
		std::cout << currentNode->getValue() << std::endl;
	}
	else 
	{	std::cout << "List is empty!" << std::endl;}
}

bool LinkedList::isEmpty()
{LOG
	return (length_ == 0);	
}

void LinkedList::insert(int data)
{LOG
	LinkedNode* newNode = new LinkedNode(data);

	if (head_ == nullptr) //Empty List
	{	head_ = newNode;}
	else //Tail Insertion
	{	tail_->setNextLinkedNode(newNode);}

	tail_ = newNode;
	length_++;
}

void LinkedList::deleteNode(int data)
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

// Getters
int LinkedList::getLength()
{LOG
	return length_;
}

LinkedNode* LinkedList::getHead()
{LOG
	return head_;
}

LinkedNode* LinkedList::getTail()
{LOG
	return tail_;
}

// Setters
void LinkedList::setHead(LinkedNode* head)
{LOG
	if (head_ == nullptr)
	{	
		head_ = head;
		tail_ = head;
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
	else
	{	
		tail_->setNextLinkedNode(tail);
		tail_ = tail;
	}
	length_++;
}