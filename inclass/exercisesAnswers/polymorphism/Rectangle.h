// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rrybarcz

// Class Declaration

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"

class Rectangle : public Shape
{ 
	private:
		int width_,length_; // End all member attributes with a trailing underscore _
	public: 
		Rectangle(); // Default Constructor
		Rectangle(int width,int length); // Non-Default Constructor (Parameterized)
		virtual ~Rectangle(); // Carry the virtual keyword here just in-case.
		virtual double getArea(); // Carry the virtual keyword here just in-case.
}; // Don't forget your semicolon to end each class!

#endif