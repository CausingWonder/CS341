#ifndef SQUARE_H
#define SQUARE_H

// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rrybarcz

#include "Rectangle.h"

class Square : public Rectangle
{
	public:
		Square();
		Square(int);
		virtual ~Square();
};

#endif