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
    This header file contains the definition for the block class
    which extents the shape class.

    Implementations of these methods are contained in Block.cpp
    -------------------------------------------------------
 */

#ifndef CBLOCK_H
#define CBLOCK_H

#include<GL/glut.h>
#include"Shape.hpp"

class Block : public Shape{

public:
	GLfloat vertex[8][3]; //Block verticies
	GLint face[6][4]; //Block faces
	GLint colorCode;

	Block();
	void drawFace(int);
	void draw();
};

#endif
