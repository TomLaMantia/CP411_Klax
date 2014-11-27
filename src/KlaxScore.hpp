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
    This header file contains the definition of a the KlaxScore class

    Implementations of these methods are contained in KlaxScore.cpp
    -------------------------------------------------------
 */

#ifndef CKLAXSCORE_H
#define CKLAXSCORE_H

#include<string.h>
#include<GL/glut.h>

const int POINTS_PER_KLAX = 50;

class KlaxScore{
public:
	/* Score variables and output */
	void *font;
	void *fonts;
	int numberOfKlaxes;
	int currentScore;

	KlaxScore();
	void draw();
	void addKlaxToScore();
	void output(GLfloat, GLfloat, GLfloat, char *);
};

#endif
