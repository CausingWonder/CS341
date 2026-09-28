// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include <iomanip>
#include "Student.h"

// Helpers
void Student::calculate_gpa()
{
	if (creditHours_ > 0 && gradePoints_ > 0)
	{
		gpa_ = (double)gradePoints_ /creditHours_;
		calculate_letterGrade();
	} 
	else;
}

void Student::calculate_letterGrade()
{
	if (gpa_>=3.7)
	   {
	       letterGrade_ = 'A';
	   }
	   else if (gpa_>=2.7)
	   {
	       letterGrade_ = 'B';
	   }
	   else if (gpa_>=1.7)
	   {
	       letterGrade_ = 'C';
	   }
	   else if (gpa_>=0.7)
	   {
	       letterGrade_ = 'D';
	   }
	   else
	   {
	       letterGrade_ = 'F';
	   }
}


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

Student::Student(std::string id, int gradePoints, int creditHours)
{
	id_ = id;
	gradePoints_ = gradePoints;
	creditHours_ = creditHours;
	gpa_ = 0.0;
	letterGrade_ = ' ';
	calculate_gpa();
}


// Getters
std::string Student::get_id()
{
	return id_;
}

int Student::get_gradePoints()
{
	return gradePoints_;
}

int Student::get_creditHours()
{
	return creditHours_;
}

double Student::get_gpa()
{
	return gpa_;
}

char Student::get_letterGrade()
{
	return letterGrade_;
}


// Setters
void Student::set_gradePoints(int gradePoints)
{
	gradePoints_ = gradePoints;
	calculate_gpa();
}

void Student::set_creditHours(int creditHours)
{
	creditHours_ = creditHours;
	calculate_gpa();
}


// Implementers
void Student::print_info() 
{
    std::cout << "ID: " << id_ << " Grade Points: " << gradePoints_ << " Credit Hours: " << creditHours_ << std::endl;
};

void Student::print_gpa() 
{
	std::cout << "ID: " << id_ << " GPA: " << std::setprecision(3) << gpa_ << " Letter Grade: " << letterGrade_ << std::endl;
};