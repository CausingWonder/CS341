// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#ifndef TREENODE_H
#define TREENODE_H

#include "Node.h"

class TreeNode : public Node
{
	public:
		TreeNode();
		TreeNode(int);
		~TreeNode();
		void setLeftChild(TreeNode* leftChild);
		void setRightChild(TreeNode* rightChild);
		void setParent(TreeNode* parent);
		TreeNode* getLeftChild();
		TreeNode* getRightChild();
		TreeNode* getParent();
		
	private:
		TreeNode* leftChild_;
		TreeNode* rightChild_;
		TreeNode* parent_;

};

#endif