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
	std::cout << std::endl << "***LinkedNode***" << std::endl;
	LinkedNode* node1 = new LinkedNode(2);
	std::cout << "node1: 2" << std::endl;
	LinkedNode* node2 = new LinkedNode(13);
	std::cout << "node2: 13" << std::endl;
	LinkedNode* node3 = new LinkedNode(7);
	std::cout << "node3: 7" << std::endl;

	std::cout << "node1 has " << (node1->hasPrevLinkedNode() ? "has previous ERROR" : "no previous") << std::endl;

	node1->setNextLinkedNode(node2);
	node2->setPrevLinkedNode(node1);
	node2->setNextLinkedNode(node3);
	node3->setPrevLinkedNode(node2);

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

	return 0;
}