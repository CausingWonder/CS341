#include <iostream>
#include <string>

class Shape
{
	protected:
		std::string name_;

	public:
		Shape();
		~Shape();
		std::string getName();
};