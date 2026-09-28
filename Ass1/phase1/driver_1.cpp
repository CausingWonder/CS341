// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include <iostream>
#include <fstream>

int main () 
{
	// Variable Declarations
	std::string fileName(" ");
	int lineCounter(0);

	std::string studentID[30];
	int gradePoints[30];
	int creditHours[30];

	// Collect Data
	std::cout << "Enter a file" << std::endl;
	std::cin >> fileName;

	std::ifstream fileScanner(fileName);
	if (!fileScanner.is_open())
	{
		std::cout << "Error: File not found" << std::endl;
		return 0;
	} else
	{
		while (fileScanner)
		{
			fileScanner >> studentID[lineCounter];
			fileScanner >> gradePoints[lineCounter];
			fileScanner >> creditHours[lineCounter];
			lineCounter++;
		}
	}
	
	// Output Data
	for (int i = 0; i < lineCounter; i++)
	{
		std::cout << studentID[i] << " " << gradePoints[i] << " " << creditHours[i] << std::endl;
	}

	return 0;
}