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

TreeNode::TreeNode() : TreeNode(0) {LOG}

TreeNode::TreeNode(int data) : Node(data), color_(Color::RED), leftChild_(nullptr), rightChild_(nullptr) {LOG}

TreeNode::~TreeNode() {LOG}

TreeNode* TreeNode::getLeftChild() const
{LOG
	return leftChild_;
}

TreeNode* TreeNode::getRightChild() const
{LOG
	return rightChild_;
}

TreeNode* TreeNode::getParent() const
{LOG
	return parent_;
}

Color TreeNode::getColor() const
{LOG
	return color_;
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

void TreeNode::setColor(Color color)
{LOG
	color_ = color;
}

