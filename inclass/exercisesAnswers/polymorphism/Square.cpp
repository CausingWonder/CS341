// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rrybarcz

#include "Square.h"

// This explicitly calls the Base class constructor - will be done automatically implicitly if not provided.
Square::Square() : Rectangle()
{
	name_ = "Square";
}

Square::Square(int side) : Rectangle(side, side)
{
	name_ = "Square";
}

Square::~Square()
{

}