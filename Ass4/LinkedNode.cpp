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
#define LOG std::cout << "    " << __PRETTY_FUNCTION__ << "    " << std::endl;
#endif
#else 
#define LOG ;
#endif

/// Public:
// Lifetime Methods
LinkedNode::LinkedNode() 
:Node(), nextNode_(nullptr), prevNode_(nullptr) 
{LOG}

LinkedNode::LinkedNode(Card data) 
:Node(data), nextNode_(nullptr), prevNode_(nullptr) 
{LOG}

LinkedNode::LinkedNode(const LinkedNode& prevLinkedNode) 
{LOG
	setValue(prevLinkedNode.getValue());
	nextNode_ = nullptr;
	prevNode_ = nullptr;
}

LinkedNode::~LinkedNode() 
{LOG}

// Getters
LinkedNode* LinkedNode::getNextLinkedNode() const
{LOG
	return nextNode_;
}

LinkedNode* LinkedNode::getPrevLinkedNode() const
{LOG
	return prevNode_;
}

// Setters
void LinkedNode::setNextLinkedNode(LinkedNode* nextNode)
{LOG
	nextNode_ = nextNode;
}

void LinkedNode::setPrevLinkedNode(LinkedNode* prevNode)
{LOG
	prevNode_ = prevNode;
}

// Methods
bool LinkedNode::hasNextLinkedNode()
{LOG
	return (nextNode_ != nullptr);
}

bool LinkedNode::hasPrevLinkedNode()
{LOG
	return (prevNode_ != nullptr);
}



