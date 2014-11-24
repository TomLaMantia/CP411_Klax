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
    This header file contains the definition for the planet class

    Implementations of these methods are contained in Planet.cpp
    -------------------------------------------------------
 */

#ifndef CPLANET_H
#define C_PLANET_H

#include<GL/glew.h>
#include"Shape.hpp"
#include<GL/glut.h>

class Planet: public Shape {

public:
	GLUquadricObj *sphere;
	GLdouble radius;
	GLint slices;
	GLint stacks;
	GLuint textureNum;
	Planet(GLdouble, GLint, GLint);
	void draw();
};

#endif
