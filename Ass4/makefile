SORT.exe: driver.o Card.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o DawgHop.o
	g++ driver.o Card.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o DawgHop.o -o SORT.exe

A4.exe: full_Card_driver.o Card.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o DawgHop.o
	g++ full_Card_driver.o Card.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o DawgHop.o -o A4.exe

Card.o: Card.cpp
	g++ -c Card.cpp -o Card.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

DoublyLinkedList.o: DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp -o DoublyLinkedList.o

DawgHop.o: DawgHop.cpp
	g++ -c DawgHop.cpp -o DawgHop.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

full_Card_driver.o: full_Card_driver.cpp
	g++ -c full_Card_driver.cpp -o full_Card_driver.o

SORT:
	./SORT.exe

A4:
	./A4.exe

clean:
	rm -f *.o *.exe