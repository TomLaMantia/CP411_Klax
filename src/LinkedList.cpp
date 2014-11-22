/*
 -------------------------------------------------------
 Id: 110283790
 Email: lama3790@mylaurier.ca
 Version: December 1, 2014
 -------------------------------------------------------
 */

/*
   -------------------------------------------------------
    This file contains implementation for the LinkedList class,
    which is defined in LinkedList.hpp
    -------------------------------------------------------
 */

#include"LinkedList.hpp"

LinkedList::LinkedList() {
	front = NULL;
}

/*
 -------------------------------------------------------
 Returns a pointer to a node in the list
 -------------------------------------------------------
 Preconditions:
 int targetIndex - the index of the node we want to return
 Postconditions:
 current - a pointer holding the address of the node at
 the specified index in the list
 -------------------------------------------------------
 */
BlockNode * LinkedList :: returnIndex(int targetIndex) {
	int i = 0;
	BlockNode *current = front;

	while (i != targetIndex) {
		current = current->next;
		i++;
	}
	return current;
}

void LinkedList :: incrementBlockPositionAtIndex(GLint targetIndex)
{
	int i = 0;
	BlockNode *current = front;

	while (i != targetIndex) {
		current = current->next;
		i++;
	}

	current->position -= 1;
}

/*
 -------------------------------------------------------
 Garbage disposal. Deletes every node in the list
 -------------------------------------------------------
 Preconditions:
 None
 Postconditions:
 List now empty
 -------------------------------------------------------
 */
void LinkedList::emptyListContents() {
	BlockNode *toDelete = front;
	while (toDelete != NULL) {
		front = front->next;
		delete toDelete;
		toDelete = front;
	}
}

/*
 -------------------------------------------------------
 Returns the size of a linked list
 -------------------------------------------------------
 Preconditions:
 None
 Postconditions:
 int result - the number of nodes residing in the list
 -------------------------------------------------------
 */
int LinkedList::getListSize() {
	BlockNode *current = front;
	int result = 0;

	while (current != NULL) {
		current = current->next;
		result++;
	}

	return result;
}

/*
 -------------------------------------------------------
 Inserts an object to the front of the list
 -------------------------------------------------------
 Preconditions:
	BlockNode *newNode - pointer to a BlockNode
 Postconditions:
 Object pointed by the given node will now form the front
 of the linked list
 -------------------------------------------------------
 */
void LinkedList::listInsertFront(BlockNode *newNode) {

	newNode->next = this->front;
	front = newNode;
	delete front;
}

/*
 -------------------------------------------------------
 Inserts an object to the rear of the list
 -------------------------------------------------------
 Preconditions:
 BlockNode *newNode - a pointer to the node which
 will be added to the rear
 Postconditions:
 Object pointed by the given node will now form the rear
 of the linked list
 -------------------------------------------------------
 */
void LinkedList::listInsertRear(BlockNode *newNode) {
	BlockNode *current = new BlockNode();
	current = front;

	if (front == NULL) {
		newNode->next = front;
		front = newNode;
	} else {
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = newNode;
	}
}

void LinkedList::listRemoveIndex(int targetIndex) {
	int currentIndex = 0;
	BlockNode *prev = new BlockNode();
	BlockNode *current = new BlockNode();

	prev = NULL;
	current = front;

	while (currentIndex < targetIndex) {
		prev = current;
		current = current->next;
		currentIndex++;
	}

	/* Maybe we have to remove the front node */
	if (currentIndex == 0) {
		front = front->next;
	}
	/* Maybe we have to remove the last node */
	else if (current == NULL) {
		prev->next = NULL;
	}
	/* Often, we remove from the middle */
	else {
		prev->next = current->next;
	}
}
