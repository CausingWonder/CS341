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

enum class Colour {RED, BLACK};
inline std::ostream& operator<<(std::ostream& stream, Colour colour) 
{	return stream << (bool(colour) ? "Black" : "Red");}

class TreeNode : public Node
{
	public:
		TreeNode();
		TreeNode(int);
		TreeNode(const TreeNode&);
		~TreeNode() override;

		TreeNode* getLeftChild() const;
		TreeNode* getRightChild() const;
		TreeNode* getParent() const;
		Colour getColour();

		void setLeftChild(TreeNode* leftChild);
		void setRightChild(TreeNode* rightChild);
		void setParent(TreeNode* parent);
		void setColour(Colour);
		
	private:
		TreeNode* leftChild_;
		TreeNode* rightChild_;
		TreeNode* parent_;
		Colour colour_;
};

#endif