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

// Lifecycle Methods
TreeNode::TreeNode() : TreeNode(0) {LOG}
TreeNode::TreeNode(int data) : Node(data), colour_(Colour::RED), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr) {LOG}
TreeNode::TreeNode(const TreeNode& other) : Node(other), colour_(other.colour_), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr) {LOG}
TreeNode::~TreeNode() {LOG}

// Getters 
TreeNode* TreeNode::getLeftChild() const {LOG	return leftChild_;}
TreeNode* TreeNode::getRightChild() const {LOG	return rightChild_;}
TreeNode* TreeNode::getParent() const {LOG	return parent_;}
Colour TreeNode::getColour() {LOG	return colour_;}

// Setters
void TreeNode::setLeftChild(TreeNode* leftChild) {LOG	leftChild_ = leftChild;}
void TreeNode::setRightChild(TreeNode* rightChild) {LOG	rightChild_ = rightChild;}
void TreeNode::setParent(TreeNode* parent) {LOG	parent_ = parent;}
void TreeNode::setColour(Colour colour) {LOG	colour_ = colour;}

