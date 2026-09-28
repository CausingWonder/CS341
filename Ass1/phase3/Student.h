// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#include <iostream>

class Student
{
	private:
		std::string id_;
		int gradePoints_,creditHours_;
		double gpa_;
		char letterGrade_;

		// Helpers
		void calculate_gpa(); // Calculate GPA
		void calculate_letterGrade(); // Calculate Letter Grade

    public:
		Student(); // Default Constructor
		~Student(); // Default Destructor
		Student(std::string id,int gradePoints,int creditHours); // Overloaded Constructor

		// Getters
		std::string get_id();
		int get_gradePoints();
		int get_creditHours();
		double get_gpa();
		char get_letterGrade();

		// Setters
		void set_gradePoints(int gradePoints);
		void set_creditHours(int creditHours);

		// Implementers
        void print_info(); // Print students full info
		void print_gpa(); // Print students gpa
};