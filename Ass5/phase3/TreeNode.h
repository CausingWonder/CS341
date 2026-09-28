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

enum class Color {RED, BLACK};
inline std::ostream& operator<<(std::ostream& stream, const Color& color) 
{	return stream << (bool(color) ? "Red" : "Black");}

class TreeNode : public Node
{
	public:
		TreeNode();
		TreeNode(int);
		~TreeNode() override;

		TreeNode* getLeftChild() const;
		TreeNode* getRightChild() const;
		TreeNode* getParent() const;
		Color getColor() const;

		void setLeftChild(TreeNode* leftChild);
		void setRightChild(TreeNode* rightChild);
		void setParent(TreeNode* parent);
		void setColor(Color);
		
	private:
		TreeNode* leftChild_;
		TreeNode* rightChild_;
		TreeNode* parent_;
		Color color_;
};

#endif