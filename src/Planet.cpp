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
    This file contains implementation for the planet class,
    which is defined in Planet.hpp
    -------------------------------------------------------
 */

#include"Planet.hpp"

Planet :: Planet(GLdouble rad, GLint slice, GLint stack){
	this->radius = rad;
	this->slices = slice;
	this->stacks = stack;
	this->textureNum = 0;
	this->sphere = gluNewQuadric();
}

void Planet :: draw(){
	glPushMatrix();
	ctmMultiply();
	glBindTexture(GL_TEXTURE_2D, this->textureNum);
	gluSphere(this->sphere, this->radius, this->slices, this->stacks);
	glPopMatrix();
}
