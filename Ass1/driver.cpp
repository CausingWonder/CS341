// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include <fstream>
#include <vector>
#include "Student.h"

// Function Declarations
void sort(std::vector<Student*>& studentBody);
void mergeSort(std::vector<Student*>& studentBody, int left, int right);
void merge(std::vector<Student*>& studentBody, int left, int mid, int right);

int main () 
{
	// Variable Declarations
	std::string fileName(" ");
	std::vector<Student*> studentBody;
	std::string studentID(" ");
	int gradePoints(0), creditHours(0);


	// Collect Data
	std::cout << "Enter a file" << std::endl;
	std::cin >> fileName;
	std::ifstream fileScanner(fileName);

	if (fileScanner.is_open()==false)
	{
		std::cout << "Invalid file name/directory" << std::endl;
		return 1;
	} 
	else
	{
		while(fileScanner.eof()==false)
		{
			fileScanner >> studentID;
			fileScanner >> gradePoints;
			fileScanner >> creditHours;
			studentBody.push_back(new Student(studentID, gradePoints, creditHours));
		}
	}
	fileScanner.close();

	// Sort Data
	sort(studentBody);

	// Output Data
	std::cout << " **** Student GPA Calculator **** " << std::endl;
	for (Student* student : studentBody)
	{
		student->print_gpa();
	}
	std::cout << "Thank you for choosing us for your GPA Calculations!" << std::endl;


	// Free Heap Memory
	for (Student* student : studentBody)
	{
		delete student;
	}

	return 0;
};


// Function Definitions
void sort(std::vector<Student*>& studentBody)
{
	mergeSort(studentBody, 0, studentBody.size() - 1);
}

void mergeSort(std::vector<Student*>& studentBody, int left, int right)
{
	// Base case: when size is 1 or less
	if (right<=left) return;

	// Recursive case
	int mid = left + (right - left) / 2;
	mergeSort(studentBody, left, mid);
	mergeSort(studentBody, mid + 1, right);
	merge(studentBody, left, mid, right);
}

void merge(std::vector<Student*>& studentBody, int left, int mid, int right)
{
	int tempLeft, tempRight;
	tempLeft = left;
	tempRight = mid + 1;
	std::vector<Student*> temp;

	// Splits list into 2 halves
	while (tempLeft <= mid && tempRight <= right) 
	{
		// Compares and adds the smaller value to temp
		if (*(studentBody[tempRight]) <= *(studentBody[tempLeft]))
		{
			temp.push_back(studentBody[tempLeft]);
			tempLeft++;
		} 
		else
		{
			temp.push_back(studentBody[tempRight]);
			tempRight++;
		}
	}

	// Copys remaining values to temp
	while (tempLeft <= mid)
	{
		temp.push_back(studentBody[tempLeft]);
		tempLeft++;
	}
	while (tempRight <=right)
	{
		temp.push_back(studentBody[tempRight]);
		tempRight++;
	}

	// Copies temp back to studentBody
	for (int index = left; index <= right; index++)
	{
		studentBody[index] = temp[index - left];
	}
}
