// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "BinarySearchTree.h"

#define DEBUG_BST false
#if DEBUG_BST
#ifndef LOCATION_DEBUG 
#define LOG std::cout << "    " << __PRETTY_FUNCTION__ << "    " << std::endl;
#endif
#else 
#define LOG ; 
#endif

BinarySearchTree::BinarySearchTree() : root_(nullptr) {LOG}

BinarySearchTree::~BinarySearchTree() {LOG}

void BinarySearchTree::insertNode(int data)
{LOG
	TreeNode* newNode = new TreeNode(data);
	root_ = insertNode(root_, newNode);

	///Below should be in RBT
	//balanceColor(root_);
	//root_->setColor(BLACK); //Root is always black
}

void BinarySearchTree::deleteNode(int data)
{LOG
	// If value exists, delete it
	root_ = deleteNode(root_, data);
}

void BinarySearchTree::print() const
{LOG
	std::cout << "In Order Traversal:   ";
	inorder(root_);
	std::cout << std::endl;

	std::cout << "Pre Order Traversal:  ";
	preorder(root_);
	std::cout << std::endl;

	std::cout << "Post Order Traversal: ";
	postorder(root_);
	std::cout << std::endl;
}

int BinarySearchTree::getHeight() const
{LOG
	return getHeight(root_);
}

int BinarySearchTree::getHeight(TreeNode* node) const
{LOG
	if (node == nullptr)
		return -1;
	
	int leftHeight = getHeight(node->getLeftChild());
	int rightHeight = getHeight(node->getRightChild());
	
	return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

TreeNode* BinarySearchTree::getRoot() const
{LOG
	return root_;
}

TreeNode* BinarySearchTree::insertNode(TreeNode* root, TreeNode* node)
{LOG
	if (root == nullptr) //Root of tree
	{	return node;}
	else
	{
		if (node->getData() < root->getData()) //Left subtree
		{
			root->setLeftChild(insertNode(root->getLeftChild(), node));
			root->getLeftChild()->setParent(root);
		}
		else //Right subtree
		{
			root->setRightChild(insertNode(root->getRightChild(), node));
			root->getRightChild()->setParent(root);
		}

		return root;
	}
}

TreeNode* BinarySearchTree::deleteNode(TreeNode* root, int data)
{LOG
	if (root == nullptr) //Tree is empty
	{	return nullptr;} 
	else if (data < root->getData()) //Left subtree
	{	root->setLeftChild(deleteNode(root->getLeftChild(), data));}
	else if (data > root->getData()) //Right subtree
	{	root->setRightChild(deleteNode(root->getRightChild(), data));}
	else //Node found
	{
		if (root->getLeftChild() == nullptr && root->getRightChild() == nullptr) //Leaf Node
		{	
			delete root;
			return nullptr;
		}
		else if (root->getLeftChild() == nullptr) //Right child only
		{
			TreeNode* node = root->getRightChild(); //Becomes replaceNode(root, root->getRightChild())

			//Turn the rest of the function into a helper function. replaceNode(TreeNode* dest, TreeNode* src)
			root->setValue(node->getData());
			root->setLeftChild(node->getLeftChild());
			root->setRightChild(node->getRightChild());

			node->setLeftChild(nullptr);
			node->setRightChild(nullptr);
			node->setParent(nullptr);

			delete node;
			return root;
		}
		else if (root->getRightChild() == nullptr) //Left child only
		{
			//Use replaceNode helper function. replaceNode(root, root->getLeftChild())
			TreeNode* node = root->getLeftChild();
			delete root;
			return node;
		}
		else //Two Children
		{
			TreeNode* node = root->getRightChild();

			while (node != nullptr && node->getLeftChild() != nullptr)
			{
				node = node->getLeftChild();
			}

			root->setValue(node->getData());
			root->setRightChild(deleteNode(root->getRightChild(), node->getData()));
		}
	}

	return root;
}

void BinarySearchTree::inorder(TreeNode* root) const
{LOG
	if (root == nullptr)
	{	return;}
	else;

	inorder(root->getLeftChild());
	std::cout << root->getData() << " ";
	inorder(root->getRightChild());
}

void BinarySearchTree::preorder(TreeNode* root) const
{LOG
	if (root == nullptr)
	{	return;}
	else;
	
	std::cout << root->getData() << " ";
	preorder(root->getLeftChild());
	preorder(root->getRightChild());
}

void BinarySearchTree::postorder(TreeNode* root) const
{LOG
	if (root == nullptr)
	{	return;}
	else;

	postorder(root->getLeftChild());
	postorder(root->getRightChild());
	std::cout << root->getData() << " ";
}