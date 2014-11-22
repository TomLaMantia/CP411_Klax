/*
 -------------------------------------------------------
 Author: Tom LaMantia
 Id: 110283790
 Email: lama3790@mylaurier.ca
 Version: December 1, 2014

 This is the main program for my CP411 final project
 -------------------------------------------------------
 */

#include<GL/glut.h>
#include<windows.h>
#include"ViewingEye.hpp"
#include"Block.hpp"
#include"GameArea.hpp"
#include"BlockNode.hpp"
#include<unistd.h>
#include"ConveyorBelt.hpp"
#include"Paddle.hpp"
#include"LinkedList.hpp"
#include"Block.hpp"

using namespace std;

//Program global variables
CONST int windowPositionX = 100;
CONST int windowPositionY = 100;
CONST int windowWidth = 800;
CONST int windowHeight = 800;
CONST int conveyorBeltDelay = 500;
CONST int randomInsertTarget = 10;

//Program global objects
ViewingEye myCamera;
GameArea myGameArea;
ConveyorBelt myConveyorBelt;
Paddle myPaddle;

/*  Set positions for near and far clipping planes:  */
GLfloat vangle = 40.0, dnear = 1.0, dfar = 10.0;

/* Global program variables */
int numDisplayFunctionIterations = 0;

//Function prototypes
void Init(void);
void DisplayFunction(void);
void KeyboardFunction(GLubyte, int, int);
void KeyboardPaddleControl(GLint, GLint, GLint);

void KeyboardFunction(GLubyte key, int x, int y) {

	GLint colorOfRemovedBlock;
	GLint currentPaddleLane = myPaddle.lanePosition;

	if(key == 'x'){
		colorOfRemovedBlock = myPaddle.dumpPaddle();
	}

	if(colorOfRemovedBlock != -1){
		myGameArea.insertNewBlock(currentPaddleLane, colorOfRemovedBlock);
	}
}

void KeyboardPaddleControl(GLint arrowKey, GLint x, GLint y) {

	if (arrowKey == GLUT_KEY_LEFT) {

		if (myPaddle.lanePosition > 0) {
			myPaddle.lanePosition -= 1;
		}

	} else if (arrowKey == GLUT_KEY_RIGHT) {

		if (myPaddle.lanePosition < 2) {
			myPaddle.lanePosition += 1;
		}
	}
}

void DisplayFunction(void)
{
	numDisplayFunctionIterations++;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myConveyorBelt.moveConveyor();

	if(numDisplayFunctionIterations == randomInsertTarget){
		myConveyorBelt.insertBlockOnConveyor();
		numDisplayFunctionIterations = 0;
	}

	BlockNode *removedNode;
	removedNode = myConveyorBelt.removeBlockFromConveyor();

	if(removedNode != NULL && removedNode->lane == myPaddle.lanePosition)
	{
		myPaddle.placeBlockOnPaddle(removedNode);
	}

	myGameArea.draw();
	myConveyorBelt.draw();
	myPaddle.draw();

	glFlush();
	glutSwapBuffers();

	Sleep(conveyorBeltDelay);
}

void Init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(vangle, 1.0, dnear, dfar);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(myCamera.viewPositon.x, myCamera.viewPositon.y,
			myCamera.viewPositon.z, myCamera.rotationPoint.x,
			myCamera.rotationPoint.y, myCamera.rotationPoint.z,
			myCamera.viewUpDirection.x, myCamera.viewUpDirection.y,
			myCamera.viewUpDirection.z);

	myGameArea.insertNewBlock(1,1);
	myGameArea.insertNewBlock(0,0);
	myGameArea.insertNewBlock(2,2);
	myGameArea.insertNewBlock(2,1);
	myGameArea.insertNewBlock(2,3);
	myGameArea.printGameAreaTest();

	//myConveyorBelt.insertBlockOnConveyor();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(windowPositionX, windowPositionY);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Klax (By Tom LaMantia)");

	Init();
	glutDisplayFunc(DisplayFunction);
	glutKeyboardFunc(KeyboardFunction);
	glutSpecialFunc(KeyboardPaddleControl);

	/* Do it */
	glutMainLoop();

	return 0;
}
