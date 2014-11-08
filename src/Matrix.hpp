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
    This header file contains the definition for a matrix class

    Implementations of these methods are contained in Matrix.cpp
    -------------------------------------------------------
 */

#ifndef CMATRIX_H
#define CMATRIX_H

#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include"ViewingEye.hpp"

using namespace std;

class Matrix {

public:
	GLfloat mat[4][4];
	Matrix();
	void matrixPreMultiply(Matrix *);
	void translate(GLfloat, GLfloat, GLfloat);
	void transpose();
	void multiplyVector(GLfloat *);
	void rotate(GLfloat, GLfloat, GLfloat, GLfloat);
	void normalize();
};

#endif
