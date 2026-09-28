#include <iostream>
#include "Rectangle.h"

int main () 
{
    Rectangle r1(5,3); // Stored in stack
    Rectangle* r2 = new Rectangle(5,3); // Stored in heap

    std::cout << "Area r1: " << r1.area() << std::endl; // Accessing obj stored on stack with dot operators

    std::cout << "Area r2: " << r2->area() << std::endl; // Accessing obj stored on heap with arrow operator
	std::cout << "Area r2: " << (*r2).area() << std::endl; // Dereference pointer then access with dot operator

	Rectangle r3; // Default constructor, Stored in stack
	std::cout << "Area r3: " << r3.area() << std::endl; // Accessing obj stored on stack with dot operators

	delete r2; // Frees up memory by calling the destructor

    return 0;
}