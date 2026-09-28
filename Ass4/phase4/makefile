LIST.exe: driver.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o
	g++ driver.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o -o LIST.exe

FULL_int_LIST.exe: full_int_driver.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o
	g++ full_int_driver.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o -o FULL_int_LIST.exe

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

DoublyLinkedList.o: DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp -o DoublyLinkedList.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

full_int_driver.o: full_int_driver.cpp
	g++ -c full_int_driver.cpp -o full_int_driver.o

run:
	./LIST.exe

run_full_int:
	./FULL_int_LIST.exe

clean:
	rm -f *.o *.exe