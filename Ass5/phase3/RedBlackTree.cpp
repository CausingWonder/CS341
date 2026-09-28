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

RedBlackTree::RedBlackTree() : BinarySearchTree() {LOG}

RedBlackTree::~RedBlackTree() {LOG}

void RedBlackTree::insertNode(int data)
{LOG
	BinarySearchTree::insertNode(data);
	balanceColor(getRoot());
}

void RedBlackTree::balanceColor(TreeNode* node)
{LOG
	if (node->getParent() == nullptr) 
	{	node->setColor(Color::BLACK);}
	else;
}
