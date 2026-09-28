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
		/// Defualt constructor
		LinkedNode();

		/**
		 * Initializing constructor.
		 *
		 * @param[in]      	data
		 */		
		LinkedNode(Card);

		/**
		 * Copy constructor.
		 * Creates a new LinkedNode with the same Node data and nullptrs.
		 *
		 * @param[in]		prevLinkedNode
		 */		
		LinkedNode(const LinkedNode&);

		/// Destructor
		~LinkedNode();

		/**
		 * Check if there is a next linked node.
		 *
		 * @return		true if there is a next linked node, false otherwise
		 */
		bool hasNextLinkedNode();

		/**
		 * Check if there is a previous linked node.
		 *
		 * @return		true if there is a previous linked node, false otherwise
		 */
		bool hasPrevLinkedNode();

		/**
		 * Returns pointer to the next linked node.
		 *
		 * @return		pointer to next linked node
		 */
		LinkedNode* getNextLinkedNode() const;	

		/**
		 * Returns pointer to the previous linked node.
		 *
		 * @return		pointer to previous linked node
		 */
		LinkedNode* getPrevLinkedNode() const;

		/**
		 * Sets the next linked node pointer.
		 *
		 * @param[in]		nextNode - pointer to the next linked node
		 */
		void setNextLinkedNode(LinkedNode*);

		/**
		 * Sets the previous linked node pointer.
		 *
		 * @param[in]		prevNode - pointer to the previous linked node
		 */
		void setPrevLinkedNode(LinkedNode*);

	private:
		LinkedNode* nextNode_;
		LinkedNode* prevNode_;
};

#endif