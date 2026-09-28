// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rrybarcz

// Shape Class (Declaration)

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

class Shape
{
	protected:
		std::string name_;

	public: 
		Shape();
		virtual ~Shape(); 
		virtual double getArea() = 0; // Pure Virtual (Abstract) Method --> MUST be implemented in derived class.
		virtual std::string getName();
};

#endif