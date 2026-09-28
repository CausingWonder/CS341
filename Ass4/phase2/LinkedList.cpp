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
		delete oldHead;
	} 
	tail_ = nullptr;
}

// Methods
void LinkedList::printList()
{LOG
	LinkedNode* node = head_;
	
	if (node != nullptr)
	{
		while (node->hasNextLinkedNode())
		{
			std::cout << node->getValue() << 	" -> ";
			node = node->getNextLinkedNode();
		}
	
		std::cout << node->getValue() << std::endl;
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

	if (data == head_->getValue())
	{
		if (head_ == tail_)
		{
			delete head_;
			head_ = nullptr;
			tail_ = nullptr;
		}
		else if (data == head_->getValue())
		{
			LinkedNode* newHead = nullptr;

			newHead = head_->getNextLinkedNode();
			head_->setNextLinkedNode(nullptr);
			delete head_;
			head_ = newHead;
		} 
		else
		{
			// FINISH IN CLASS WED
		}
	} else;
	length_--;
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