// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include "Student.h"

// Constructors
Student::Student() 
{
	id_ = " ";
	gradePoints_ = 0;
	creditHours_ = 0;
}

Student::~Student() 
{
}

Student::Student(std::string id,int gradePoints,int creditHours)
{
	id_ = id;
	gradePoints_ = gradePoints;
	creditHours_ = creditHours;
}


// Getters
std::string Student::get_ID()
{
	return id_;
}

int Student::get_GradePoints()
{
	return gradePoints_;
}

int Student::get_CreditHours()
{
	return creditHours_;
}


// Setters
void Student::set_GradePoints(int gradePoints)
{
	gradePoints_ = gradePoints;
}

void Student::set_CreditHours(int creditHours)
{
	creditHours_ = creditHours;
}


// Implementers
void Student::printInfo() 
{
    std::cout << "ID: " << id_ << " Grade Points: " << gradePoints_ << " Credit Hours: " << creditHours_ << std::endl;
};

