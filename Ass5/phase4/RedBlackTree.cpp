// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "RedBlackTree.h"

#define DEBUG_RBT false
#if DEBUG_RBT
#ifndef LOCATION_DEBUG 
#define LOG std::cout << "    " << __PRETTY_FUNCTION__ << "    " << std::endl;
#endif
#else 
#define LOG ; 
#endif

// Lifecycle Methods
RedBlackTree::RedBlackTree() : BinarySearchTree() {LOG}
RedBlackTree::RedBlackTree(const RedBlackTree& other) : BinarySearchTree(other) {LOG}
RedBlackTree::~RedBlackTree() {LOG}

// Overridden Methods
void RedBlackTree::insertNode(int data)
{LOG
	BinarySearchTree::insertNode(data);
	TreeNode* root = getRoot();

	// Find inserted node of value data
	TreeNode* newNode = root;
	while (newNode)
	{
		if (data < newNode->getData())
		{	newNode = newNode->getLeftChild();}
		else if (data > newNode->getData())
		{	newNode = newNode->getRightChild();}
		else
		{	break;}
	}

	balanceColour(root, newNode);
	setRoot(root);
}

// RBT Logical Helper Methods
void RedBlackTree::balanceColour(TreeNode*& root, TreeNode*& newNode)
{LOG
	TreeNode* parent = newNode->getParent();

	if (!parent) //Parent is nullptr, so newNode is root & black
	{
		newNode->setColour(Colour::BLACK);
		return;
	}
	else if (parent->getColour() == Colour::BLACK) //If parent is black, no adj red nodes
	{	return;}
	else //Parent is red
	{
		TreeNode* grandParent = parent->getParent();
		if (!grandParent) //GrandParent is nullptr, so parent is root & black
		{
			parent->setColour(Colour::BLACK);
			return;
		}
		else //Parent is red & grandParent exist
		{
			if (parent == grandParent->getRightChild()) //Parent is red & grandParent exist & leftUncle
			{
				TreeNode* LeftUncle = grandParent->getLeftChild();
				if (LeftUncle != nullptr && LeftUncle->getColour() == Colour::RED) //NonParent is leftUncle & red
				{
					parent->setColour(Colour::BLACK);
					grandParent->setColour(Colour::RED);
					LeftUncle->setColour(Colour::BLACK);
					balanceColour(root, grandParent); 
				}
				else //NonParent is leftUncle & black
				{
					if (newNode == parent->getLeftChild()) //NewNode is leftSibling
					{
						rotateRight(root, parent); //NewNode rotated up to parent's position
						TreeNode* temp = newNode;
						newNode = parent;
						parent = temp;
					}
					parent->setColour(Colour::BLACK);
					grandParent->setColour(Colour::RED);
					rotateLeft(root, grandParent);
				}
			}
			else
			{
				TreeNode* rightUncle = grandParent->getRightChild();
				if (rightUncle != nullptr && rightUncle->getColour() == Colour::RED) //NonParent is rightUncle & red
				{
					parent->setColour(Colour::BLACK);
					grandParent->setColour(Colour::RED);
					rightUncle->setColour(Colour::BLACK);
					balanceColour(root, grandParent); 
				}
				else //NonParent is rightUncle & black
				{
					if (newNode == parent->getRightChild()) //NewNode is rightSibling
					{
						rotateLeft(root, parent); //NewNode rotated up to parent's position
						TreeNode* temp = newNode;
						newNode = parent;
						parent = temp;
					}
					parent->setColour(Colour::BLACK);
					grandParent->setColour(Colour::RED);
					rotateRight(root, grandParent);
				}
			}
		}
	} 	
} 	
void RedBlackTree::rotateLeft(TreeNode*& root, TreeNode*& newNode)
{LOG
	// Save og right child and re-assign children
	TreeNode* rightNode = newNode->getRightChild(); //Save og right child by assignment
	newNode->setRightChild(rightNode->getLeftChild()); //Save og left child by newNode right child
	if (rightNode->getLeftChild()) //If og right child has left child...
	{	rightNode->getLeftChild()->setParent(newNode);} //then update there parent link to match newNode
	else;

	// Set new relation's between rightNode and subroot
	rightNode->setParent(newNode->getParent()); //Set rightNode to subroot by setting there og g-parent as parent
	if (!newNode->getParent()) //If newNode is leaving root...
	{	root = rightNode;} //then rightNode becomes new root
	else if (newNode == newNode->getParent()->getLeftChild()) //If newNode is leaving left child...
	{	newNode->getParent()->setLeftChild(rightNode);} //then rightNode new parent sees rightNode as left child
	else //If newNode is leaving right child...
	{	newNode->getParent()->setRightChild(rightNode);} //then rightNode new parent sees rightNode as right child

 	// Set new relation's between newNode and rightNode
	rightNode->setLeftChild(newNode); //Set newNode as left child of rightNode
	newNode->setParent(rightNode); //Set newNode parent as rightNode
}
void RedBlackTree::rotateRight(TreeNode*& root, TreeNode*& newNode)
{LOG
	// Save og left child and re-assign children
	TreeNode* leftNode = newNode->getLeftChild(); //Save og left child by assignment
	newNode->setLeftChild(leftNode->getRightChild()); //Save og right child by newNode left child
	if (newNode->getLeftChild()) //If og left child has right child...
	{    newNode->getLeftChild()->setParent(newNode);} //then update there parent link to match newNode
	else;

	// Set new relation's between leftNode and subroot
	leftNode->setParent(newNode->getParent()); //Set leftNode to subroot by setting there og g-parent as parent
	if (!newNode->getParent()) //If newNode is leaving root...
	{    root = leftNode;} //then leftNode becomes new root
	else if (newNode == newNode->getParent()->getRightChild()) //If newNode is leaving right child...
	{    newNode->getParent()->setRightChild(leftNode);}
	else //If newNode is leaving left child...
	{    newNode->getParent()->setLeftChild(leftNode);} //then leftNode new parent sees leftNode as left child
	
	// Set new relation's between newNode and leftNode
	leftNode->setRightChild(newNode); //Set newNode as right child of leftNode
	newNode->setParent(leftNode); //Set newNode parent as leftNode
}