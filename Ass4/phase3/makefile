LIST.exe: driver.o  Node.o LinkedNode.o LinkedList.o
	g++ driver.o Node.o LinkedNode.o LinkedList.o -o LIST.exe

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

test:
	valgrind --log-file=valgrind.txt ./LIST.exe

run:
	./LIST.exe

clean:
	rm -f *.o *.exe