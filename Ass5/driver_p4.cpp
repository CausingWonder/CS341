// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "RedBlackTree.h"
#include <fstream>

#define INPUTFILE_DEFAULT "data.txt"

void readDeliminatedTXT(RedBlackTree* tree, std::string inPutFile = INPUTFILE_DEFAULT, bool display = true);
void report(RedBlackTree* tree);

int main()
{
	RedBlackTree* rbTree = new RedBlackTree();
	readDeliminatedTXT(rbTree);
	report(rbTree);
	delete rbTree;
	return 0;
}


void readDeliminatedTXT(RedBlackTree* tree, std::string inPutFile, bool display)
{
	std::ifstream inputFile(inPutFile);
	int num;
	if (!inputFile.is_open()) 
	{	std::cout << "Error opening file: " << inPutFile << std::endl;}
	else
	{
		std::cout << "Reading: " << inPutFile << "     ";
		while (inputFile >> num) 
		{	
			if (display) 
			{std::cout << num << " ";}
			else;
			tree->insertNode(num);
		}
	}
	inputFile.close();
	std::cout << std::endl;
}

void report(RedBlackTree* tree)
{
	tree->print();
	std::cout << "Root: " << tree->getRoot()->getData() << " " << tree->getRoot()->getColour() << std::endl;
	std::cout << "Height: " << tree->getHeight() << std::endl;
}