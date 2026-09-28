// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rrybarcz

// Source/Implementation File

// Links the implementation to the declaration.
#include "Rectangle.h" // Should only ever have one (1) include here!

// Class :: <scope resolution operator> Constructor/Destructor/Method/Attribute
Rectangle::Rectangle(int x, int y) : length_(0), width_(0)
{
	name_ = "Rectangle";
	
	if (x >= 0)
	{
		length_ = x;
	}
	
	if (y >= 0)
	{
		width_ = y;
	}
} 

Rectangle::Rectangle() : length_(0), width_(0)
{
	name_ = "Rectangle";
}

Rectangle::~Rectangle()
{

}

double Rectangle::getArea() 
{
	return width_ * length_;
} 