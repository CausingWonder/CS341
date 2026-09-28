// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Node.h"

class LinkedNode : public Node
{
	public:
		LinkedNode();
		LinkedNode(int Data);
		~LinkedNode();

		bool hasNextLinkedNode();

		LinkedNode* getNextLinkedNode();

		void setNextLinkedNode(LinkedNode* nextNode_);

	private:
		LinkedNode* nextNode_;

};

#endif