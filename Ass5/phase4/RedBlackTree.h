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
		RedBlackTree(const RedBlackTree&); 
		~RedBlackTree() override; 

		void insertNode (int) override;

	private:
		void balanceColour(TreeNode*&, TreeNode*&);
		void rotateLeft(TreeNode*&, TreeNode*&);
		void rotateRight(TreeNode*&, TreeNode*&);
};

#endif