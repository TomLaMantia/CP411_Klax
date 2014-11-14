/*
 -------------------------------------------------------
 Author: Tom LaMantia
 Id: 110283790
 Email: lama3790@mylaurier.ca
 Version: October 10, 2014
 -------------------------------------------------------
 */

/*
   -------------------------------------------------------
    This header file contains the definition of a LinkedList

    Implementations of these methods are contained in LinkedList.cpp
    -------------------------------------------------------
 */

#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include"BlockNode.hpp"

class LinkedList {

protected:
	BlockNode *front;

public:
	LinkedList();
	void listInsertFront(BlockNode *);
	void listInsertRear(BlockNode *);
	void emptyListContents();
	int getListSize();
	BlockNode * returnIndex(int);
	void listRemoveIndex(int);
};

#endif

