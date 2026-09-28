
#include "LinkedNode.h"

int main() 
{
	LinkedNode l1;
	std::cout << "data_: " << l1.getValue() << std::endl;

	LinkedNode l2;
	l1.setNextLinkedNode(&l2);
		
	return 0;
}