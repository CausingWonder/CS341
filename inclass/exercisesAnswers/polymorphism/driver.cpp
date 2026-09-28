// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rrybarcz

// Driver Program

// Need to include all references refered to here.
#include <iostream>
#include "Square.h"
#include "Triangle.h"

int main()
{
	// Ensures our pointer is pointed at nothing (nullptr)...
	Shape * ptrShape1 = nullptr;
	
	// Shape Pointer pointing at a Rectangle object.
	ptrShape1 = new Rectangle(2,3); // Stage #1 and #2
	// Stage #3: Lines 22-38
	Shape * ptrShape2 = new Triangle(2,4);

	Shape * ptrShape3 = new Square(3);

	Shape * myArray[3];

	myArray[0] = ptrShape1;
	myArray[1] = ptrShape2;
	myArray[2] = ptrShape3;

	for (int i=0; i < 3; i++)
	{
		std::cout << myArray[i]->getName() << " Area: " << myArray[i]->getArea() << std::endl;
	}
	
	// We don't want any memory leaks!
	delete ptrShape1; // Stage 4
	delete ptrShape2;
	delete ptrShape3;

	return 0;
}