// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "DoublyLinkedList.h"

int main() 
{
	std::cout << std::endl << "***LinkedNode***" << std::endl;
	LinkedNode* node1 = new LinkedNode(2);
	std::cout << "node1: 2" << std::endl;
	LinkedNode* node2 = new LinkedNode(13);
	std::cout << "node2: 13" << std::endl;
	LinkedNode* node3 = new LinkedNode(7);
	std::cout << "node3: 7" << std::endl;
	
	std::cout << "node1 has " << (node1->hasPrevLinkedNode() ? "has previous ERROR" : "no previous") << std::endl;
	
	node1->setNextLinkedNode(node2); // 1 -> 2
	node2->setPrevLinkedNode(node1); // 2 -> 1
	node2->setNextLinkedNode(node3); // 2 -> 3
	node3->setPrevLinkedNode(node2); // 3 -> 2
	
	std::cout << "***Forward vs Backwards***" << std::endl;
	LinkedNode* currentNode = node1;
	while (currentNode->hasNextLinkedNode())
	{
		std::cout << currentNode->getValue() << " -> ";
		currentNode = currentNode->getNextLinkedNode();
	}
	std::cout << currentNode->getValue() << std::endl;
	
	currentNode = node3;
	while (currentNode->hasPrevLinkedNode())
	{
		std::cout << currentNode->getValue() << " -> ";
		currentNode = currentNode->getPrevLinkedNode();
	}
	std::cout << currentNode->getValue() << std::endl;
	
	delete node1;
	delete node2;
	delete node3;


	std::cout << std::endl << "***LinkedList***" << std::endl;
	std::cout << "List 1" << std::endl;
	LinkedList* list1 = new LinkedList();

	std::cout << "List is " << (list1->isEmpty() ? "empty" : "not empty") << std::endl;
	
	std::cout << std::endl << "***Insertion***" << std::endl;
	list1->insert(5);
	std::cout << "Inserted 5" << std::endl;
	list1->insert(12);
	std::cout << "Inserted 12" << std::endl;
	list1->insert(7);
	std::cout << "Inserted 7" << std::endl;
	list1->insert(11);
	std::cout << "Inserted 11" << std::endl;
	
	std::cout << std::endl << "***Check List***" << std::endl;
	list1->printList();
	std::cout << "Length: " << list1->getLength() << std::endl;
	
	std::cout << std::endl << "***Getters***" << std::endl;
	if (!list1->isEmpty())
	{
		std::cout << "Head: " << list1->getHead()->getValue() << std::endl;
		std::cout << "Tail: " << list1->getTail()->getValue() << std::endl;
	}
	else
	{	std::cout << "List is empty so, head=tail=nullptr" << std::endl;}
	
	std::cout << std::endl << "***Setters***" << std::endl;
	LinkedList* list2 = new LinkedList();
	std::cout << "List 2" << std::endl;
	LinkedNode* onlyHead = new LinkedNode(20);
	list2->setHead(onlyHead);
	std::cout << "Head only: " << list2->getHead()->getValue() << std::endl;
	
	LinkedList* list3 = new LinkedList();
	std::cout << "List 3" << std::endl;
	LinkedNode* onlyTail = new LinkedNode(2);
	list3->setTail(onlyTail);
	std::cout << "Tail only: " << list3->getTail()->getValue() << std::endl;
	
	LinkedNode* newHead = new LinkedNode(7);
	list3->setHead(newHead);
	std::cout << "New head: " << list3->getHead()->getValue() << std::endl;
	
	LinkedNode* newTail = new LinkedNode(14);
	list3->setTail(newTail);
	std::cout << "New tail: " << list3->getTail()->getValue() << std::endl;
	
	std::cout << "List 2: ";
	list2->printList();
	std::cout << "Length: " << list2->getLength() << std::endl;
	std::cout << "List 3: ";
	list3->printList();
	std::cout << "Length: " << list3->getLength() << std::endl;
	
	std::cout << std::endl << "***Delete***" << std::endl;
	delete list1;
	delete list2;
	delete list3;


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

	return 0;
}