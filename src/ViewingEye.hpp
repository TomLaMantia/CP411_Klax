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
    This header file contains the definition for the ViewingEye
    class. This class contains the information to pass to GluLookAt
    to implement transformations to viewing coordinates.

    Implementations of these methods are contained in ViewingEye.cpp
    -------------------------------------------------------
 */

#ifndef CVIEWINGEYE_H
#define CVIEWINGEYE_H

#include<iostream>
#include"Point3D.hpp"
#include"Matrix.hpp"
#include<GL/glut.h>

class ViewingEye{

public:
	Point3D viewPositon;
	Point3D viewDirectionVector;
	Point3D viewUpDirection ;
	Point3D rotationPoint;

	int screenWidth, screenHeight;

	double focalLength, aperture, eyeSeperation;

	ViewingEye();
	void rotateViewingEye(GLfloat, GLfloat, GLfloat, GLfloat);
	void translate(GLfloat, GLfloat, GLfloat);
	void resetEye();
	void increaseZoom(GLfloat);
	void decreaseZoom(GLfloat);
	void translateEyePosition(GLfloat, GLfloat, GLfloat);

};

#endif
