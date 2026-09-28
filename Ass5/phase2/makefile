.DEFAULT_GOAL := p2

P2.exe: Node.o TreeNode.o BinarySearchTree.o driver_p2.o
	g++ Node.o TreeNode.o BinarySearchTree.o driver_p2.o -o P2.exe

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o
TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o
BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o

driver_p2.o: driver_p2.cpp
	g++ -c driver_p2.cpp -o driver_p2.o

p2:
	make P2.exe
	./P2.exe

clean:
	rm -f *.o *.exe