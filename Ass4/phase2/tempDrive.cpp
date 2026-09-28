// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "LinkedList.h"
#include <iostream>

int main() 
{
	std::cout << "=== Phase II LinkedList Testing ===" << std::endl << std::endl;
	
	// Test 1: Create an empty list
	std::cout << "Test 1: Creating an empty LinkedList..." << std::endl;
	LinkedList* list = new LinkedList();
	
	// Test 2: Check if empty
	std::cout << "Test 2: Checking if list is empty..." << std::endl;
	if (list->isEmpty()) {
		std::cout << "   List is empty (CORRECT)" << std::endl;
	} else {
		std::cout << "   List is NOT empty (ERROR)" << std::endl;
	}
	std::cout << "   Length: " << list->getLength() << std::endl << std::endl;
	
	// Test 3: Insert nodes as specified in Phase II example
	std::cout << "Test 3: Inserting values (15, 7, 10)..." << std::endl;
	std::cout << "Inserting 15..." << std::endl;
	list->insert(15);
	std::cout << "Inserting 7..." << std::endl;
	list->insert(7);
	std::cout << "Inserting 10..." << std::endl;
	list->insert(10);
	std::cout << std::endl;
	
	// Test 4: Print the list
	std::cout << "Test 4: Printing the list..." << std::endl;
	list->printList();
	std::cout << "Length: " << list->getLength() << std::endl << std::endl;
	
	// Test 5: Check head and tail
	std::cout << "Test 5: Checking head and tail values..." << std::endl;
	if (list->getHead() != nullptr) {
		std::cout << "   Head value: " << list->getHead()->getValue() << std::endl;
	}
	if (list->getTail() != nullptr) {
		std::cout << "   Tail value: " << list->getTail()->getValue() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 6: Check if list is empty after insertions
	std::cout << "Test 6: Checking if list is empty after insertions..." << std::endl;
	if (list->isEmpty()) {
		std::cout << "   List is empty (ERROR)" << std::endl;
	} else {
		std::cout << "   List is NOT empty (CORRECT)" << std::endl;
	}
	std::cout << std::endl;
	
	// Test 7: Additional insertions
	std::cout << "Test 7: Inserting additional values (5, 12)..." << std::endl;
	list->insert(5);
	list->insert(12);
	std::cout << "Updated list:" << std::endl;
	list->printList();
	std::cout << "Length: " << list->getLength() << std::endl << std::endl;
	
	// Test 8: Test setHead method
	std::cout << "Test 8: Testing setHead()..." << std::endl;
	LinkedNode* newHead = new LinkedNode(99);
	std::cout << "Creating new node with value 99 and setting as head..." << std::endl;
	list->setHead(newHead);
	std::cout << "List after setHead:" << std::endl;
	list->printList();
	std::cout << "Length: " << list->getLength() << std::endl;
	if (list->getHead() != nullptr) {
		std::cout << "Head value: " << list->getHead()->getValue() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 9: Test setTail method
	std::cout << "Test 9: Testing setTail()..." << std::endl;
	LinkedNode* newTail = new LinkedNode(200);
	std::cout << "Creating new node with value 200 and setting as tail..." << std::endl;
	list->setTail(newTail);
	std::cout << "List after setTail:" << std::endl;
	list->printList();
	std::cout << "Length: " << list->getLength() << std::endl;
	if (list->getTail() != nullptr) {
		std::cout << "Tail value: " << list->getTail()->getValue() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 10: Test setHead on empty list
	std::cout << "Test 10: Testing setHead() on empty list..." << std::endl;
	LinkedList* list2 = new LinkedList();
	LinkedNode* firstNode = new LinkedNode(50);
	std::cout << "Setting head on empty list with value 50..." << std::endl;
	list2->setHead(firstNode);
	std::cout << "List after setHead on empty list:" << std::endl;
	list2->printList();
	std::cout << "Length: " << list2->getLength() << std::endl << std::endl;
	
	// Test 11: Test setTail on empty list
	std::cout << "Test 11: Testing setTail() on empty list..." << std::endl;
	LinkedList* list3 = new LinkedList();
	LinkedNode* onlyNode = new LinkedNode(75);
	std::cout << "Setting tail on empty list with value 75..." << std::endl;
	list3->setTail(onlyNode);
	std::cout << "List after setTail on empty list:" << std::endl;
	list3->printList();
	std::cout << "Length: " << list3->getLength() << std::endl << std::endl;
	
	
	// Cleanup
	std::cout << "Cleaning up memory..." << std::endl;
	delete list;
	delete list2;
	
	std::cout << std::endl << "=== All Phase II Tests Complete ===" << std::endl;
	
	return 0;
}