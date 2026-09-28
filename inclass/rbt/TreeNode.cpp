// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "TreeNode.h"

#define DEBUG_TN false
#if DEBUG_TN
#ifndef LOCATION_DEBUG 
#defineLOG std::cout << "    " << __PRETTY_FUNCTION__ << "    " << std::endl;
#endif
#else 
#define LOG ;
#endif

TreeNode::TreeNode() : TreeNode(0)
{LOG
}

TreeNode::TreeNode(int data) : Node(data), leftChild_(nullptr), rightChild_(nullptr)
{LOG
}

TreeNode::~TreeNode()
{LOG
}

void TreeNode::setLeftChild(TreeNode* leftChild)
{LOG
	leftChild_ = leftChild;
}

void TreeNode::setRightChild(TreeNode* rightChild)
{LOG
	rightChild_ = rightChild;
}

void TreeNode::setParent(TreeNode* parent)
{LOG
	parent_ = parent;
}

TreeNode* TreeNode::getLeftChild()
{LOG
	return leftChild_;
}

TreeNode* TreeNode::getRightChild()
{LOG
	return rightChild_;
}

TreeNode* TreeNode::getParent()
{LOG
	return parent_;
}