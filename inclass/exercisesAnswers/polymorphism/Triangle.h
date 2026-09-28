#ifndef TRIANGLE_H
#define TRIANGLE_H

// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rrybarcz

#include "Shape.h"

// Triangle Class
class Triangle : public Shape
{
	private:
		int base_, height_;
	public:
		Triangle();
		Triangle(int, int);
		virtual ~Triangle();
		virtual double getArea();

};

#endif