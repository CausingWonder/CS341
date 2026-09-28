// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment,
// with the exception of in class coding
//
// Jrouse

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "LinkedList.h"

class DoublyLinkedList : public LinkedList
{
	public:
		/// Defualt constructor
		DoublyLinkedList();

		/**
		 * Copy constructor.
		 *
		 * @param[in]		other
		 */
		DoublyLinkedList(const DoublyLinkedList&);

		/// Destructor
		~DoublyLinkedList();

		/***
		 * Inserts a new node in a bouble linked list
		 * after the given previous node w/ given data.
		 * 
		 * @param[in]		prevNode - pointer to the previous node
		 * @param[in]		data - card data to insert
		 */
		virtual void insertLinkedNode(LinkedNode*, Card) override;

		/***
		 * Deletes a node w/ the given data from
		 * the doubly linked list.
		 * 
		 * @param[in]		data - card data to delete
		 */
		virtual void deleteNode(Card) override;

		/***
		 * Prints the doubly linked list.
		 */
		virtual void printList() const override;
};

#endif