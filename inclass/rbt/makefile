RUN.exe: driver.o Node.o TreeNode.o BinarySearchTree.o
	g++ driver.o Node.o TreeNode.o BinarySearchTree.o -o RUN.exe

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o

BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

run:
	./RUN.exe

clean:
	rm -f *.o *.exe