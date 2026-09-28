// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedNode.h"

class LinkedList
{
	public:
		/// Defualt constructor
		LinkedList();

		/**
		 * Copy constructor.
		 *
		 * @param[in]		other
		 */		
		LinkedList(const LinkedList&);
		
		/// Destructor
		~LinkedList();

		/***
		 * Get the head node of the linked list.
		 * 
		 * @return		pointer to head node
		 */
		LinkedNode* getHead() const;

		/***
		 * Get the tail node of the linked list.
		 * 
		 * @return		pointer to tail node
		 */
		LinkedNode* getTail() const;

		/***
		 * Get the length of the linked list.
		 * 
		 * @return		length of linked list
		 */
		int getLength() const;

		/***
		 * Set the head node of the linked list.
		 * 
		 * @param[in]		head - pointer to new head node
		 */
		void setHead(LinkedNode*);

		/***
		 * Set the tail node of the linked list.
		 * 
		 * @param[in]		tail - pointer to new tail node
		 */
		void setTail(LinkedNode*);

		/**
		 * Inserts a new node w/ given data at the end of the list.
		 * Uses insertLinkedNode(tail_, data) to perform the insertion.
		 * 
		 * @param[in]		data - card data to insert
		 */
		void insert(Card);

		/**
		 * Deletes the first node found w/ the given data.
		 * 
		 * @param[in]		data - card data to delete
		 */
		virtual void deleteNode(Card);

		/**
		 * Prints the linked list.
		 */
		virtual void printList() const;

		/**
		 * Checks if the linked list is empty.
		 * 
		 * @return		true if the list is empty, false otherwise
		 */
		bool isEmpty();

	protected:
		int length_;

		/***
		 * Inserts a new node in a linked list
		 * after the given previous node w/ given data.
		 * 
		 * @param[in]		prevNode - pointer to the previous node
		 * @param[in]		data - card data to insert
		 */
		virtual void insertLinkedNode(LinkedNode*, Card);

	private:
		LinkedNode* head_;
		LinkedNode* tail_;

};

#endif