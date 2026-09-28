  #include "BinarySearchTree.h"

  int main()
  {
/*	TreeNode* root = new TreeNode(10);
	TreeNode* leftChild = new TreeNode(7);
	TreeNode* rightChild = new TreeNode(15);

	root->setLeftChild(leftChild);
	root->setRightChild(rightChild);

	std::cout << "Right Child: " << root->getRightChild()->getValue() << std::endl;
	std::cout << "Left Child: " << root->getLeftChild()->getValue() << std::endl;

	delete root;
	delete leftChild;
	delete rightChild;*/

	BinarySearchTree* myTree = new BinarySearchTree();

	std::cout << "Insert 10, 7, 15, 22" << std::endl;
	myTree->insertNode(10);
	myTree->insertNode(7);
	myTree->insertNode(15);
	myTree->insertNode(22);
	report(myTree);

	std::cout << "Delete w/ 2 Children" << std::endl;
	myTree->deleteNode(10);
	report(myTree);

	std::cout << "Delete Left Child" << std::endl;
	myTree->deleteNode(7);
	report(myTree);

	std::cout << "Delete Right Child" << std::endl;
	myTree->deleteNode(15);
	report(myTree);

	delete myTree;
	return 0;



	//PHASE 4 TEST USE: 10, 7, 15, 12, 13
  }




   void report(BinarySearchTree* tree)
   {
  tree->print();
  std::cout << "Root: " << tree->getRoot()->getData() << std::endl;
   }