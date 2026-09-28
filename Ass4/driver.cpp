// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include <iostream>
#include <fstream>
#include "DawgHop.h"


/**
 * Creates a doubly linked list of Cards from a given file.
 * 
 * @param[in]		file - name of the input file
 * @param[out]		dll - pointer to the DoublyLinkedList to populate
 */
void createCardsDLL(std::string, DoublyLinkedList*);

int main()
{
	std::string inputFile(" ");
	DoublyLinkedList* dll = new DoublyLinkedList;
	int dawgHop(0);
	DawgHop sort;

	std::cout << "Enter a file" << std::endl;
	std::cin >> inputFile;

	createCardsDLL(inputFile, dll);

	dll->printList();
	std::cout << "Length: " << dll->getLength() << std::endl;

	sort.insertionSort(dll, dawgHop);
	dll->printList();
	std::cout << "Length: " << dll->getLength() << std::endl;
	std::cout << "DawgHops: " << dawgHop << std::endl;

	delete dll;
}

void createCardsDLL(std::string file, DoublyLinkedList* dll)
{
	std::ifstream inputFile(file);
	if (inputFile.is_open()) 
	{
		int suit, face;
		inputFile >> suit; //First line is not needed
		while (inputFile >> suit >> face) 
		{	dll->insert(Card(suit, face));}
	}
	else;
	inputFile.close();
}