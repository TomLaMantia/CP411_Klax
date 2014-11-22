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
#include"ViewingEye.hpp"
#include"Block.hpp"
#include"GameArea.hpp"

using namespace std;

//Program global variables
CONST int windowPositionX = 100;
CONST int windowPositionY = 100;
CONST int windowWidth = 800;
CONST int windowHeight = 800;

//Program global objects
ViewingEye myCamera;
GameArea myGameArea;

/*  Set positions for near and far clipping planes:  */
GLfloat vangle = 40.0, dnear = 1.0, dfar = 10.0;

//Function prototypes
void Init(void);
void DisplayFunction(void);
void KeyboardFunction(unsigned char, int, int);

void KeyboardFunction(unsigned char key, int x, int y)
{

}

void DisplayFunction(void)
{
	myGameArea.draw();

	glFlush();
	glutSwapBuffers();
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

//	myGameArea.insertNewBlock(1,1);
//	myGameArea.insertNewBlock(0,0);
//	myGameArea.insertNewBlock(2,2);
//	myGameArea.insertNewBlock(1,1);
//	myGameArea.insertNewBlock(2,3);
//	myGameArea.printGameAreaTest();
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

	/* Do it */
	glutMainLoop();

	return 0;
}
