.DEFAULT_GOAL := full

FULL.exe: Node.o TreeNode.o BinarySearchTree.o driver_full.o
	g++ Node.o TreeNode.o BinarySearchTree.o driver_full.o -o FULL.exe
P1.exe: Ingest.o driver_p1.o
	g++ Ingest.o driver_p1.o -o P1.exe
P2.exe: Node.o TreeNode.o BinarySearchTree.o driver_p2.o
	g++ Node.o TreeNode.o BinarySearchTree.o driver_p2.o -o P2.exe
P3.exe: Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o driver_p3.o
	g++ Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o driver_p3.o -o P3.exe
P4.exe: Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o driver_p4.o
	g++ Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o driver_p4.o -o P4.exe
P5.exe: Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o driver_p5.o
	g++ Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o driver_p5.o -o P5.exe

Ingest.o: phase1/Ingest.cpp
	g++ -c phase1/Ingest.cpp -o Ingest.o
Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o
TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o
BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o
RedBlackTree.o: RedBlackTree.cpp
	g++ -c RedBlackTree.cpp -o RedBlackTree.o

driver_p1.o: phase1/driver_p1.cpp
	g++ -c phase1/driver_p1.cpp -o driver_p1.o
driver_p2.o: phase2/driver_p2.cpp
	g++ -c phase2/driver_p2.cpp -o driver_p2.o
driver_p3.o: driver_p3.cpp
	g++ -c driver_p3.cpp -o driver_p3.o
driver_p4.o: driver_p4.cpp
	g++ -c driver_p4.cpp -o driver_p4.o
driver_p5.o: driver_p5.cpp
	g++ -c driver_p5.cpp -o driver_p5.o
driver_full.o: driver_full.cpp
	g++ -c driver_full.cpp -o driver_full.o

full:
	make FULL.exe
	./FULL.exe
p1:
	make P1.exe
	./P1.exe
p2:
	make P2.exe
	./P2.exe
p3:
	make P3.exe
	./P3.exe
p4:
	make P4.exe
	./P4.exe
p5:
	make P5.exe
	./P5.exe

clean:
	rm -f *.o *.exe