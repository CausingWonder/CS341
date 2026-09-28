#include "TreeNode.h"
#include <iostream>

class BinarySearchTree
{
	public:
		BinarySearchTree();
		~BinarySearchTree();
		void insertNode (int);
		void deleteNode(int);
		void print();
		TreeNode* getRoot() const;

	private:
		TreeNode* root_;
		
		TreeNode* insertNode (TreeNode*, TreeNode*);
		TreeNode* deleteNode (TreeNode*, int);
		void setRoot(TreeNode* root);
		void inorder(TreeNode* root);
		void preorder(TreeNode* root);
		void postorder(TreeNode* root);
};