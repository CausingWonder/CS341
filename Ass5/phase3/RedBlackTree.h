// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "BinarySearchTree.h"
#include <iostream>

class RedBlackTree : public BinarySearchTree
{
	public:
		RedBlackTree();
		RedBlackTree(const RedBlackTree&); //IMPLEMENT
		~RedBlackTree() override; //IMPLEMENT

		void insertNode (int) override;

	private:
		void balanceColor(TreeNode*);
};

#endif