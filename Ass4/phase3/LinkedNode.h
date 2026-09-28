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
		LinkedNode(int);
		~LinkedNode();

		bool hasNextLinkedNode();
		bool hasPrevLinkedNode();

		LinkedNode* getNextLinkedNode();
		LinkedNode* getPrevLinkedNode();

		void setNextLinkedNode(LinkedNode*);
		void setPrevLinkedNode(LinkedNode*);

	private:
		LinkedNode* nextNode_;
		LinkedNode* prevNode_;

};

#endif