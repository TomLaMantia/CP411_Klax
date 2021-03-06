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
    This header file contains the definition for the GameArea class

    Implementations of these methods are contained in GameArea.cpp
    -------------------------------------------------------
 */

#ifndef CGAMEAREA_H
#define CGAMEAREA_H

#include<GL/glut.h>
#include"Block.hpp"

class GameArea{

public:
	Block gameAreaMatrix[3][3];
	GameArea();
	GLint checkVerticalKlax();
	GLint checkHorizontalKlax();
	GLint checkLeftDiagonalKlax();
	GLint checkRightDiagonalKlax();
	bool checkGameAreaFull();
	void breakDownVerticalKlax(GLint);
	void breakDownHorizontalKlax(GLint);
	void breakDownLeftDiagonalKlax();
	void breakDownRightDiagonalKlax();
	void printGameAreaTest();
	void draw();
	void reset();
	bool insertNewBlock(GLint, GLint);

};

#endif
