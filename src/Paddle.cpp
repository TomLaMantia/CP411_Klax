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
 This file contains implementation for the Paddle class,
 which is defined in Paddle.hpp
 -------------------------------------------------------
 */

#include"Paddle.hpp"

Paddle::Paddle() {

	this->paddleNode = NULL;
	this->lanePosition = 1;
}

void Paddle::draw() {

	GLfloat paddleOffsetX;

	if (this->lanePosition == 0) {
		paddleOffsetX = -0.5;
	} else if (this->lanePosition == 1) {
		paddleOffsetX = 0;
	} else if (this->lanePosition == 2) {
		paddleOffsetX = 0.5;
	}

	glLineWidth(4.0);
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
		glVertex3f(paddleOffsetX - 0.1, 0, 1.6);
		glVertex3f(paddleOffsetX + 0.1, 0, 1.6);
		glVertex3f(paddleOffsetX + 0.1, -0.1, 1.6);
		glVertex3f(paddleOffsetX - 0.1, -0.1, 1.6);
	glEnd();
}

