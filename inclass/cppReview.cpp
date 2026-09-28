//0827,0903
#include <iostream>

class Rectangle 
{
    int width_,height_;

    public:
        Rectangle(int width,int height)
        {
            width_ = width;
            height_ = height;
        }

        int area () 
        {
            return width_ * height_;
        }
};

int main () 
{
    Rectangle r1(5,3); // Stored in stack
    Rectangle *r2 = new Rectangle(5,3); // Stored in heap

    std::cout << "Area r1: " << r1.area() << std::endl;
    std::cout << "Area r2: " << r2->area() << std::endl;

    return 0;
}