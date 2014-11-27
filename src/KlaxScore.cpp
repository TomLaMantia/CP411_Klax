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
    This file contains implementation for the KlaxScore class,
    which is defined in KlaxScore.hpp
    -------------------------------------------------------
 */

#include"KlaxScore.hpp"

KlaxScore :: KlaxScore(){
	this->currentScore = 0;
	this->numberOfKlaxes = 0;
	this->font = GLUT_BITMAP_HELVETICA_12;
	this->fonts = GLUT_BITMAP_9_BY_15;
}

void KlaxScore :: addKlaxToScore(){
	this->numberOfKlaxes++;
	this->currentScore = this->numberOfKlaxes * POINTS_PER_KLAX;
}

/* Credit: Mark J. Kilgard, 1994. Provided by Dr. H Fan in CP411 resources*/
void KlaxScore :: output(GLfloat x, GLfloat y, GLfloat z, char *string)
{
  int len, i;

  glRasterPos3f(x, y, z);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(this->font, string[i]);
  }
}

void KlaxScore :: draw(){
	char default_score_message[] = "Score:";
	char default_klax_message[] = "Klaxes:";
	char strScore[10];
	char strNumKlaxes[5];
	itoa(this->numberOfKlaxes, strNumKlaxes, 10);
	itoa(this->currentScore, strScore, 10);
	glColor3f(1,0,0);
	output(-1.2, -1, 0.1, default_score_message);
	output(-1.2, -1.1, 0.1, strScore);
	output(0.8, -1, 0.1, default_klax_message);
	output(0.8, -1.1, 0.1, strNumKlaxes);
}
