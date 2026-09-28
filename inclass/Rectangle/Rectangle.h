#include <iostream>
#include "shape.h"

class Rectangle  : public Shape
{
    int width_,height_;

    public:
        Rectangle(int width,int height);
		Rectangle(); // Default constructor
		~Rectangle(); // Default destructor
        int area ();
};