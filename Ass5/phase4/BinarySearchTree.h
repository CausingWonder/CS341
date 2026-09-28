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
#include <vector>

class BinarySearchTree
{
	public:
		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree&); 
		virtual ~BinarySearchTree();

		virtual void insertNode(int);
		void deleteNode(int);

		void print() const;
		int getHeight() const;
		TreeNode* getRoot() const;

	protected:
		void setRoot(TreeNode*);

	private:
		TreeNode* root_;
		//int height_;

		void destroyTree(TreeNode*);
		TreeNode* copyTree(TreeNode*);

		TreeNode* insertNode(TreeNode*, TreeNode*);
		TreeNode* deleteNode(TreeNode*, int);

		int getHeight(TreeNode*) const;

		void inorder(const TreeNode*) const;
		void preorder(const TreeNode*) const;
		void postorder(const TreeNode*) const;
		void levelorder(TreeNode*, int, std::vector<std::vector<TreeNode*>>&) const;
		void levelorderTable(TreeNode* root) const;
};

#endif