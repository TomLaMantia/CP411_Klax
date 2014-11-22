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
    This header file contains the definition for the paddle class.

    Implementations of these methods are contained in Paddle.cpp
    -------------------------------------------------------
 */

#ifndef CPADDLE_H
#define CPADDLE_H

#include<GL/glut.h>
#include"BlockNode.hpp"

class Paddle{

public:
	BlockNode *paddleNode;
	GLint lanePosition;
	Paddle();
	void draw();
};

#endif
