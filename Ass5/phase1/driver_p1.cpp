// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "ingest.h"

int main()
{
	std::string inputFile(" ");

	std::cout << "Enter a file" << std::endl;
	std::cin >> inputFile;
	readDeliminatedTXT(inputFile);

	return 0;
}