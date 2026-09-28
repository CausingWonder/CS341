// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "Ingest.h"

void readDeliminatedTXT(std::string inPutFile, bool display)
{
	std::ifstream inputFile(inPutFile);
	int num;
	if (!inputFile.is_open()) 
	{	std::cout << "Error opening file: " << inPutFile << std::endl;}
	else
	{
		std::cout << "Reading " << inPutFile << std::endl;
		while (inputFile >> num) 
		{	
			if (display) 
			{std::cout << num << " ";}
		}
	}
	inputFile.close();
}
