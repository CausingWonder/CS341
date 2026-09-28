#include "Rectangle.h"

Rectangle::Rectangle (int width,int height)
{
	name_ = "Rectangle";
    width_ = width;
    height_ = height;
};

int Rectangle::area () 
{
    return width_ * height_;
};

Rectangle::Rectangle() 
{
	width_ = 1;
	height_ = 1;
}

Rectangle::~Rectangle() 
{
}