/*
 -------------------------------------------------------
 Author: Tom LaMantia
 Id: 110283790
 Email: lama3790@mylaurier.ca
 Version: December 1, 2014
 -------------------------------------------------------
 */

/*
   -------------------------------------------------------
    This header file contains the definition for the block node class
    which extents the shape class.

    Implementations of these methods are contained in BlockNode.cpp
    -------------------------------------------------------
 */

#ifndef CBLOCKNODE_H
#define CBLOCKNODE_H

#include"Block.hpp"
#include"GL/glut.h"

class BlockNode{
public:
	Block data;
	GLint lane; //the lane the block is in. Range [0,2]
	GLint position; //the position in the lane

};

#endif
