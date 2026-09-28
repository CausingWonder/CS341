
#include "LinkedList.h"

int main() 
{
	LinkedList* list;
	list->insert(5);
	list->insert(7);
	list->insert(11);
	list->insert(12);
		
	list->printList();

	delete list;

	return 0;
}