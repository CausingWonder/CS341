// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "LinkedNode.h"

#define DEBUG_LN false
#if DEBUG_LN
#ifndef LOCATION_DEBUG 
#defineLOG std::cout << "    " << __PRETTY_FUNCTION__ << "    " << std::endl;
#endif
#else 
#define LOG ;
#endif

LinkedNode::LinkedNode() : Node(), nextNode_(nullptr), prevNode_(nullptr)
{LOG
}

LinkedNode::LinkedNode(int data) : Node(data), nextNode_(nullptr), prevNode_(nullptr)
{LOG
}

LinkedNode::~LinkedNode()
{LOG
	if (hasNextLinkedNode())
	{	
		nextNode_ = nullptr;
		prevNode_ = nullptr;
		delete nextNode_;
		delete prevNode_;
	} 
	else{}
}

bool LinkedNode::hasNextLinkedNode()
{LOG
	if (nextNode_ == nullptr)
	{	return false;}
	else
	{	return true;}
	
	return 0;
}

bool LinkedNode::hasPrevLinkedNode()
{LOG
	if (prevNode_ == nullptr)
	{	return false;}
	else
	{	return true;}
	
	return 0;
}

LinkedNode* LinkedNode::getNextLinkedNode()
{LOG
	return nextNode_;
}

LinkedNode* LinkedNode::getPrevLinkedNode()
{LOG
	return prevNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode* nextNode)
{LOG
	nextNode_ = nextNode;
}

void LinkedNode::setPrevLinkedNode(LinkedNode* prevNode)
{LOG
	prevNode_ = prevNode;
}