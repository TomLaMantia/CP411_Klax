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
    This header file contains the definition for a shape class
    which extents the shape class.

    Implementations of these methods are contained in Shape.cpp
    -------------------------------------------------------
 */

#ifndef CSHAPE_H
#define CSHAPE_H

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include "Matrix.hpp"

using namespace std;

class Shape{
protected:
	Matrix MC; //the Model coordinate system in (X, Y, Z, 0)
	GLfloat scaleFactor; // scale factor

public:
	Shape();  // constructor
	//virtual ~Shape();  // destructor

	Matrix getMC();
	// function to do the CTM * MC
	void ctmMultiply();
	// to change the scale factor
	void scaleChange(GLfloat x);
	// to translate the MC origin
	void translate(GLfloat tx, GLfloat ty, GLfloat tz);
	// to rotate the MC with respect to a local axis.
	void rotateMc(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	// to rotate the MC including both vectors and origin
	void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	// to rotate the origin of MC and keep the vector changed
	void rotateOrigin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	// draw function must be overwritten
	virtual void draw() = 0;
	//To reset the shape to
	void resetShape();
};

#endif
