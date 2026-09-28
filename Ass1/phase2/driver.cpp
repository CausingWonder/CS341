// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"

int main () 
{
	// Variable Declarations
	std::string fileName(" ");
	std::vector<Student*> studentsData;
	std::string studentID(" ");
	int gradePoints(0), creditHours(0);



	// Collect Data
	std::cout << "Enter a file" << std::endl;
	std::cin >> fileName;

	std::ifstream fileScanner(fileName);
	if (!fileScanner.is_open())
	{
		std::cout << "Invalid file name/directory" << std::endl;
		return 1;
	} 
	else
	{
		while(!fileScanner.eof())
		{
			fileScanner >> studentID;
			fileScanner >> gradePoints;
			fileScanner >> creditHours;
			studentsData.push_back(new Student(studentID, gradePoints, creditHours));
		}
	}

	// Output Data
	std::cout << " **** Student GPA Calculator **** " << std::endl;
	for (Student* student : studentsData)
	{
		student->printInfo();
	}
	std::cout << "Thank you for choosing us for your GPA Calculations!" << std::endl;

	// Free Memory
	for (Student* student : studentsData)
	{
		delete student;
	}

	return 0;
}