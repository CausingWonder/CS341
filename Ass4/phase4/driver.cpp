// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
	std::cout << std::endl << "***DoublyLinkedList***" << std::endl;
	DoublyLinkedList* dll = new DoublyLinkedList();
	
	std::cout << std::endl << "***Insertion***" << std::endl;
	dll->insert(5);
	std::cout << "Inserted 5" << std::endl;
	dll->insert(12);
	std::cout << "Inserted 12" << std::endl;
	dll->insert(7);
	std::cout << "Inserted 7" << std::endl;
	dll->insert(11);
	std::cout << "Inserted 11" << std::endl;
	
	std::cout << std::endl << "***Check List***" << std::endl;
	dll->printList();
	std::cout << "Length: " << dll->getLength() << std::endl;

	std::cout << std::endl << "***Delete middle***" << std::endl;
	dll->deleteNode(7);
	dll->printList();
	std::cout << "Length: " << dll->getLength() << std::endl;

	std::cout << std::endl << "***Delete head***" << std::endl;
	dll->deleteNode(5);
	dll->printList();
	std::cout << "Length: " << dll->getLength() << std::endl;

	std::cout << std::endl << "***Delete tail***" << std::endl;
	dll->deleteNode(11);
	dll->printList();
	std::cout << "Length: " << dll->getLength() << std::endl;

	std::cout << std::endl << "***Delete only***" << std::endl;
	dll->deleteNode(12);
	dll->printList();
	std::cout << "Length: " << dll->getLength() << std::endl;

	delete dll;
}