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

Paddle :: Paddle() {

	this->paddleNode = NULL;
	this->lanePosition = 1;
}

void Paddle :: placeBlockOnPaddle(BlockNode * newPaddleNode){

	this->paddleNode = newPaddleNode;
}

GLint Paddle :: dumpPaddle(){

	GLint result = -1;

	//ovbiously, we can only dump the paddle if it has a block!
	if(this->paddleNode != NULL){
		result = this->paddleNode->data.colorCode;
		this->paddleNode = NULL;
	}

	return result;
}

void Paddle :: draw() {

	//First, draw the paddle itself

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

	//Then, if the paddle has a block on it, draw the block
	if(this->paddleNode != NULL){
		Block paddleBlock;
		paddleBlock = this->paddleNode->data;

		/* Draw block in correct lane */
		if(this->lanePosition == 0)
		{
			paddleBlock.translate(-0.5,0,0);
		}
		else if(this->lanePosition == 1)
		{
			paddleBlock.translate(0,0,0);
		}
		else if(this->lanePosition == 2)
		{
			paddleBlock.translate(0.5,0,0);
		}

		paddleBlock.translate(0,0,1.5);
		paddleBlock.draw();
	}

}

