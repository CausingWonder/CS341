// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rrybarcz

#include "Triangle.h"

Triangle::Triangle()
{
	name_ = "Triangle";
	base_ = 0;
	height_ = 0;
}

// Uses an initialization list...
Triangle::Triangle(int base, int height) : base_(base), height_(height)
{
	name_ = "Triangle";
}

Triangle::~Triangle()
{

}

double Triangle::getArea()
{
	return 0.5 * base_ * height_;
}