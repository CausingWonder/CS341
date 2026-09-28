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

Node::Node() : data_(0)
{LOG
}

Node::Node(int data) : data_(data)
{LOG
}

Node::~Node ()
{LOG
}

int Node::getData()
{LOG
	return data_;
}

void Node::setValue(int data)
{LOG
	data_ = data;
}

// Overloaded Operators
bool Node::operator==(const Node& other) const
{LOG
	return data_ == other.data_;
}

bool Node::operator<(const Node& other) const
{LOG
    return data_ < other.data_;
}

bool Node::operator>(const Node& other) const
{LOG
    return data_ > other.data_;
}