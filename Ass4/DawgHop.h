// Honor Pledge:
// 
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jrouse

#ifndef DAWGHOP_H
#define DAWGHOP_H

#include "DoublyLinkedList.h"

class DawgHop
{
	public:
		/**
		 * Performs insertion sort on a doublyLinkedList of Nodes.
		 * 
		 * @param[in]		dll - Pointer to the DoublyLinkedList to sort
		 * @param[out]		dawgHops - Reference to counter of Dawg Hops (shifts)
		 */
		void insertionSort(DoublyLinkedList*, int&);
	
	private:
		/**
		 * Helper function to recursively perform insertionSort.
		 * 
		 * @param[in]		pivotNode - Points to the current node
		 * @param[in]		dll - Pointer to the DoublyLinkedList to sort
		 * @param[out]		dawgHops - Reference to counter of Dawg Hops (shifts)
		 */
		void insertionSortHelper(LinkedNode*, DoublyLinkedList*, int&);

		/**
		 * Compares current node with the nodes to the left until,
		 * the previous node is less then current node.
		 * 
		 * @param[in]		pivotNode - Points to the current node
		 * @param[in]		pivotValue - Refrence to the value of the pivot node
		 */
		void shiftRight(LinkedNode*, int&);

		/**
		 * Swaps the values of two nodes.
		 * 
		 * @param[in]		node1 - Pointer to first node
		 * @param[in]		node2 - Pointer to second node
		 */
		void swap(LinkedNode*, LinkedNode*);
};

#endif