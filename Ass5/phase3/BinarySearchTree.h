// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include <iostream>

class BinarySearchTree
{
	public:
		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree&); //IMPLEMENT
		virtual ~BinarySearchTree();

		virtual void insertNode(int);
		void deleteNode(int);

		void print() const; 
		int getHeight() const;
		TreeNode* getRoot() const;

	private:
		TreeNode* root_;
		
		void setRoot(TreeNode*);
		void inorder(TreeNode*) const;
		void preorder(TreeNode*) const;
		void postorder(TreeNode*) const;
		int getHeight(TreeNode*) const;
		TreeNode* insertNode(TreeNode*, TreeNode*);
		TreeNode* deleteNode(TreeNode*, int);
};

#endif