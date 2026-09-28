// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#include "BinarySearchTree.h"

#define DEBUG_BST false
#if DEBUG_BST
#ifndef LOCATION_DEBUG 
#define LOG std::cout << "    " << __PRETTY_FUNCTION__ << "    " << std::endl;
#endif
#else 
#define LOG ; 
#endif

// Lifecycle Methods
BinarySearchTree::BinarySearchTree() : root_(nullptr) {LOG}
BinarySearchTree::BinarySearchTree(const BinarySearchTree& other) : root_(nullptr)
{LOG
	root_ = copyTree(other.root_);
}
BinarySearchTree::~BinarySearchTree() 
{LOG
	destroyTree(root_);
}

// Lifecycle Helper Methods
void BinarySearchTree::destroyTree(TreeNode* node)
{LOG
	if (node == nullptr)
	{	return;}
	else;

	destroyTree(node->getLeftChild());
	destroyTree(node->getRightChild());
	delete node;
}
TreeNode* BinarySearchTree::copyTree(TreeNode* node)
{LOG
	if (node == nullptr)
	{	return nullptr;}
	else;

	TreeNode* newNode = new TreeNode(node->getData());
	newNode->setColour(node->getColour());

	newNode->setLeftChild(copyTree(node->getLeftChild()));
	if (newNode->getLeftChild() != nullptr)
	{	newNode->getLeftChild()->setParent(newNode);}
	else;

	newNode->setRightChild(copyTree(node->getRightChild()));
	if (newNode->getRightChild() != nullptr)
	{	newNode->getRightChild()->setParent(newNode);}
	else;

	return newNode;
}

// Node Control Methods
void BinarySearchTree::insertNode(int data)
{LOG
	TreeNode* newNode = new TreeNode(data);
	root_ = insertNode(root_, newNode);
}
void BinarySearchTree::deleteNode(int data)
{LOG
	root_ = deleteNode(root_, data);
}
TreeNode* BinarySearchTree::insertNode(TreeNode* root, TreeNode* node)
{LOG
	if (root == nullptr) //Root of tree
	{
		node->setParent(nullptr);
		return node;
	}
	else
	{
		if (node->getData() < root->getData()) //Left subtree
		{
			root->setLeftChild(insertNode(root->getLeftChild(), node));
			root->getLeftChild()->setParent(root);
		}
		else //Right subtree
		{
			root->setRightChild(insertNode(root->getRightChild(), node));
			root->getRightChild()->setParent(root);
		}
		return root;
	}
}
TreeNode* BinarySearchTree::deleteNode(TreeNode* root, int data)
{LOG
	if (root == nullptr) //Tree is empty
	{	return nullptr;} 
	else if (data < root->getData()) //Left subtree
	{	root->setLeftChild(deleteNode(root->getLeftChild(), data));}
	else if (data > root->getData()) //Right subtree
	{	root->setRightChild(deleteNode(root->getRightChild(), data));}
	else //Node found
	{
		if (root->getLeftChild() == nullptr && root->getRightChild() == nullptr) //Leaf Node
		{	
			delete root;
			return nullptr;
		}
		else if (root->getLeftChild() == nullptr) //Right child only
		{
			TreeNode* node = root->getRightChild(); 

			root->setValue(node->getData());
			root->setLeftChild(node->getLeftChild());
			root->setRightChild(node->getRightChild());

			node->setLeftChild(nullptr);
			node->setRightChild(nullptr);
			node->setParent(nullptr);

			delete node;
			return root;
		}
		else if (root->getRightChild() == nullptr) //Left child only
		{
			TreeNode* node = root->getLeftChild();
			delete root;
			return node;
		}
		else //Two Children
		{
			TreeNode* node = root->getRightChild();

			while (node != nullptr && node->getLeftChild() != nullptr)
			{	node = node->getLeftChild();}

			root->setValue(node->getData());
			root->setRightChild(deleteNode(root->getRightChild(), node->getData()));
		}
	}
	return root;
}

// Getters and Setters
int BinarySearchTree::getHeight() const 
{LOG	
	//return ((height_!=0) ? height_ : getHeight(root_));
	return getHeight(root_);
}
int BinarySearchTree::getHeight(TreeNode* node) const
{LOG
	if (node == nullptr)
	{	return 0;}
	else;
	
	int leftHeight = getHeight(node->getLeftChild());
	int rightHeight = getHeight(node->getRightChild());
	
	return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}
TreeNode* BinarySearchTree::getRoot() const {LOG	return root_;}
void BinarySearchTree::setRoot(TreeNode* root) {LOG	root_ = root;}

// Traversal Methods
void BinarySearchTree::print() const
{LOG
	std::cout << "In Order Traversal:   ";
	inorder(root_);
	std::cout << std::endl;

	std::cout << "Pre Order Traversal:  ";
	preorder(root_);
	std::cout << std::endl;

	std::cout << "Post Order Traversal: ";
	postorder(root_);
	std::cout << std::endl;

	std::cout << "Level Order Traversal:" << std::endl;
	levelorderTable(root_);
}
void BinarySearchTree::inorder(const TreeNode* root) const
{LOG
	if (root == nullptr)
	{	return;}
	else;

	inorder(root->getLeftChild());
	std::cout << root->getData() << " ";
	inorder(root->getRightChild());
}
void BinarySearchTree::preorder(const TreeNode* root) const
{LOG
	if (root == nullptr)
	{	return;}
	else;
	
	std::cout << root->getData() << " ";
	preorder(root->getLeftChild());
	preorder(root->getRightChild());
}
void BinarySearchTree::postorder(const TreeNode* root) const
{LOG
	if (root == nullptr)
	{	return;}
	else;

	postorder(root->getLeftChild());
	postorder(root->getRightChild());
	std::cout << root->getData() << " ";
}
void BinarySearchTree::levelorder(TreeNode* root, int level, std::vector<std::vector<TreeNode*>>& nodes) const
{LOG
	if (root == nullptr)
	{	return;}
	else;

	// Increment level vector size
	if (level >= nodes.size())
	{	nodes.push_back({});}
	else;

	nodes[level].push_back(root);


	levelorder(root->getLeftChild(), level + 1, nodes);
	levelorder(root->getRightChild(), level + 1, nodes);
}
void BinarySearchTree::levelorderTable(TreeNode* root) const
{LOG
	std::vector<std::vector<TreeNode*>> nodes;
	//height_ = 0;
	levelorder(root, 0, nodes);

	for (const std::vector<TreeNode*>& level : nodes)
	{
		std::cout << "Level: " << (&level - &nodes[0] + 1) << std::endl;

		for (TreeNode* node : level)
		{	std::cout << node->getData() << " " << node->getColour() << std::endl;}
	}
}
