// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "DawgHop.h"

int main() 
{
	std::cout << std::endl << "***LinkedNode***" << std::endl;
	LinkedNode* node1 = new LinkedNode(Card(0,2));
	std::cout << "node1: 2" << std::endl;
	LinkedNode* node2 = new LinkedNode(Card(0,13));
	std::cout << "node2: 13" << std::endl;
	LinkedNode* node3 = new LinkedNode(Card(0,7));
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
		std::cout << currentNode->getValue().print() << " -> ";
		currentNode = currentNode->getNextLinkedNode();
	}
	std::cout << currentNode->getValue().print() << std::endl;
	
	currentNode = node3;
	while (currentNode->hasPrevLinkedNode())
	{
		std::cout << currentNode->getValue().print() << " -> ";
		currentNode = currentNode->getPrevLinkedNode();
	}
	std::cout << currentNode->getValue().print() << std::endl;
	
	delete node1;
	delete node2;
	delete node3;


	std::cout << std::endl << "***LinkedList***" << std::endl;
	std::cout << "List 1" << std::endl;
	LinkedList* list1 = new LinkedList();

	std::cout << "List is " << (list1->isEmpty() ? "empty" : "not empty") << std::endl;
	
	std::cout << std::endl << "***Insertion***" << std::endl;
	list1->insert(Card(0,5));
	std::cout << "Inserted 5" << std::endl;
	list1->insert(Card(0,12));
	std::cout << "Inserted 12" << std::endl;
	list1->insert(Card(0,7));
	std::cout << "Inserted 7" << std::endl;
	list1->insert(Card(0,11));
	std::cout << "Inserted 11" << std::endl;
	
	std::cout << std::endl << "***Check List***" << std::endl;
	list1->printList();
	std::cout << "Length: " << list1->getLength() << std::endl;
	
	std::cout << std::endl << "***Getters***" << std::endl;
	if (!list1->isEmpty())
	{
		std::cout << "Head: " << list1->getHead()->getValue().print() << std::endl;
		std::cout << "Tail: " << list1->getTail()->getValue().print() << std::endl;
	}
	else
	{	std::cout << "List is empty so, head=tail=nullptr" << std::endl;}
	
	std::cout << std::endl << "***Setters***" << std::endl;
	LinkedList* list2 = new LinkedList();
	std::cout << "List 2" << std::endl;
	LinkedNode* onlyHead = new LinkedNode(Card(0,2));
	list2->setHead(onlyHead);
	std::cout << "Head only: " << list2->getHead()->getValue().print() << std::endl;
	
	LinkedList* list3 = new LinkedList();
	std::cout << "List 3" << std::endl;
	LinkedNode* onlyTail = new LinkedNode(Card(0,4));
	list3->setTail(onlyTail);
	std::cout << "Tail only: " << list3->getTail()->getValue().print() << std::endl;

	LinkedNode* newHead = new LinkedNode(Card(0,7));
	list3->setHead(newHead);
	std::cout << "New head: " << list3->getHead()->getValue().print() << std::endl;

	LinkedNode* newTail = new LinkedNode(Card(0,13));
	list3->setTail(newTail);
	std::cout << "New tail: " << list3->getTail()->getValue().print() << std::endl;

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


	std::cout << std::endl << "***Insertion Sort1 DLL1***" << std::endl;
	DoublyLinkedList* dll1 = new DoublyLinkedList();
	
	std::cout << std::endl << "***Insertion***" << std::endl;
	dll1->insert(Card(0,5));
	std::cout << "Inserted 5" << std::endl;
	dll1->insert(Card(0,7));
	std::cout << "Inserted 7" << std::endl;
	dll1->insert(Card(0,11));
	std::cout << "Inserted 11" << std::endl;
	
	std::cout << std::endl << "***Check List***" << std::endl;
	dll1->printList();
	std::cout << "Length: " << dll1->getLength() << std::endl;
	
	std::cout << std::endl << "***insertLinkedNode***" << std::endl;
	dll1->insertLinkedNode(dll1->getHead(), Card(0,3));
	std::cout << "Inserted 3 from head when empty" << std::endl;
	dll1->insertLinkedNode(dll1->getTail(), Card(0,12));
	std::cout << "Inserted 12 after tail" << std::endl;
	dll1->insertLinkedNode(dll1->getHead(), Card(0,9));
	std::cout << "Inserted 9 after head" << std::endl;
	LinkedNode* card9 = dll1->getHead()->getNextLinkedNode();
	dll1->insertLinkedNode(card9, Card(0,6));
	std::cout << "Inserted 6 after head's next (" << card9->getValue().print() << ")" << std::endl;
	dll1->insertLinkedNode(card9->getNextLinkedNode(), Card(0,13));
	std::cout << "Inserted 13 after head's next next (" << card9->getNextLinkedNode()->getValue().print() << ")" << std::endl;
	
	std::cout << std::endl;
	dll1->printList();
	std::cout << "Length: " << dll1->getLength() << std::endl;
	
	std::cout << std::endl << "***Sort1***" << std::endl;
	DawgHop sort1;
	int dawgHop = 0;
	sort1.insertionSort(dll1, dawgHop);
	dll1->printList();
	std::cout << "Length: " << dll1->getLength() << std::endl;
	std::cout << "DawgHops: " << dawgHop << std::endl;
	
	delete dll1;
	
	
	std::cout << std::endl << "***Insertion Sort1 DLL2***" << std::endl;
	DoublyLinkedList* dll2 = new DoublyLinkedList();
	
	std::cout << std::endl << "***Insertion***" << std::endl;
	dll2->insert(Card(0,12));
	std::cout << "Inserted 12" << std::endl;
	dll2->insert(Card(0,8));
	std::cout << "Inserted 8" << std::endl;
	dll2->insert(Card(0,7));
	std::cout << "Inserted 7" << std::endl;
	dll2->insert(Card(0,3));
	std::cout << "Inserted 3" << std::endl;
	
	dll2->printList();
	std::cout << "Length: " << dll2->getLength() << std::endl;

	std::cout << std::endl << "***Sort2***" << std::endl;
	DawgHop sort2;
	dawgHop = 0;
	sort2.insertionSort(dll2, dawgHop);
	dll2->printList();
	std::cout << "Length: " << dll2->getLength() << std::endl;
	std::cout << "DawgHops: " << dawgHop << std::endl;
	
	delete dll2;

	return 0;
}