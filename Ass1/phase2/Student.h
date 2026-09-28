// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include <iostream>
#include <string>

class Student
{
	private:
		std::string id_;
		int gradePoints_,creditHours_;

    public:
		Student(); // Default Constructor
		~Student(); // Default Destructor
		Student(std::string id,int gradePoints,int creditHours); // Overloaded Constructor

		// Getters
		std::string get_ID();
		int get_GradePoints();
		int get_CreditHours();

		// Setters
		void set_GradePoints(int gradePoints);
		void set_CreditHours(int creditHours);

        void printInfo(); // Print students full info
};