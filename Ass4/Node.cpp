// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "Node.h"

#define DEBUG_N false
#if DEBUG_N
#ifndef LOCATION_DEBUG 
#define LOG std::cout << "    " << __PRETTY_FUNCTION__ << "    " << std::endl;
#endif
#else 
#define LOG ; 
#endif

/// Public:
// Lifetime Methods
Node::Node() 
:data_(Card()) 
{LOG}

Node::Node(Card data) 
:data_(data) 
{LOG}

Node::Node(const Node& other) 
:data_(other.data_) 
{LOG}

Node::~Node() 
{LOG}

// Getters
Card Node::getValue() const
{LOG
	return data_;
}

// Setters
void Node::setValue(Card data)
{LOG
	data_ = data;
}
