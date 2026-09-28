// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "LinkedList.h"

int main() 
{
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

	return 0;
}