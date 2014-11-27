/*
 -------------------------------------------------------
 Author: Tom LaMantia
 Id: 110283790
 Email: lama3790@mylaurier.ca
 Version: December 1, 2014

 This is the main program for my CP411 final project
 -------------------------------------------------------
 */

#include<GL/glew.h>
#include<GL/glut.h>
#include<windows.h>
#include<unistd.h>
#include<mmsystem.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ViewingEye.hpp"
#include"KlaxScore.hpp"
#include"Block.hpp"
#include"GameArea.hpp"
#include"BlockNode.hpp"
#include"ConveyorBelt.hpp"
#include"Paddle.hpp"
#include"LinkedList.hpp"
#include"Block.hpp"
#include"Planet.hpp"

using namespace std;

//Program global variables
CONST int windowPositionX = 5;
CONST int windowPositionY = 5;
CONST int windowWidth = 800;
CONST int windowHeight = 800;
CONST int conveyorBeltDelay = 500;
CONST int randomInsertTarget = 5;

//Program global objects
ViewingEye myCamera;
GameArea myGameArea;
ConveyorBelt myConveyorBelt;
Paddle myPaddle;
GLuint textures[2];
Planet jupiter(0.5,16,16);
Planet neptune(0.3,16,16);
KlaxScore myScore;

/*  Set positions for near and far clipping planes:  */
GLfloat vangle = 40.0, dnear = 0, dfar = 10.0;

/* Global program variables */
int numDisplayFunctionIterations = 4;
int conveyorSound = 0; // 0 or 1 - decides which sound to play

//Function prototypes
void GameViewInit(void);
void TextureInit(void);
void ConveyorSound(void);
void DisplayFunction(void);
void PasteBackground(void);
void KeyboardFunction(GLubyte, int, int);
void KeyboardPaddleControl(GLint, GLint, GLint);
void updateGameplay(void);

/* Struct for holding info about textures */
struct Image {
	unsigned long sizeX;
	unsigned long sizeY;
	char *data;
};
typedef struct Image Image;

/*
 *  -------------------------------------------------------
	Opens a texture

	Function provided by Dr. Fan in A4 help
    -------------------------------------------------------
    Preconditions:  pointer to filename string
    				pointer to an image struct
    Postconditions: opens the image file in classic C style!
    -------------------------------------------------------
 */
int ImageLoad(char *filename, Image *image) {
	FILE *file;
	unsigned long size; // size of the image in bytes.
	unsigned long i; // standard counter.
	unsigned short int planes; // number of planes in image (must be 1)
	unsigned short int bpp; // number of bits per pixel (must be 24)

	char temp; // temporary color storage for bgr-rgb conversion.

	// make sure the file is there.
	if ((file = fopen(filename, "rb")) == NULL) {
		printf("File Not Found : %s\n", filename);
		return 0;
	}

	// seek through the bmp header, up to the width/height:

	fseek(file, 18, SEEK_CUR);

	// read the width

	if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
		printf("Error reading width from %s.\n", filename);
		return 0;
	}

	// read the height
	if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
		printf("Error reading height from %s.\n", filename);
		return 0;
	}

	size = image->sizeX * image->sizeY * 3;

	if ((fread(&planes, 2, 1, file)) != 1) {
		printf("Error reading planes from %s.\n", filename);
		return 0;
	}

	if (planes != 1) {
		printf("Planes from %s is not 1: %u\n", filename, planes);
		return 0;
	}

	// read the bitsperpixel
	if ((i = fread(&bpp, 2, 1, file)) != 1) {
		printf("Error reading bpp from %s.\n", filename);
		return 0;
	}

	if (bpp != 24) {
		printf("Bpp from %s is not 24: %u\n", filename, bpp);
		return 0;
	}

	// seek past the rest of the bitmap header.
	fseek(file, 24, SEEK_CUR);

	image->data = (char *) malloc(size);
	if (image->data == NULL) {
		printf("Error allocating memory for color-corrected image data");
		return 0;
	}

	if ((i = fread(image->data, size, 1, file)) != 1) {
		printf("Error reading image data from %s.\n", filename);
		return 0;
	}

	for (i = 0; i < size; i += 3) { // reverse all of the colors. (bgr -> rgb)
		temp = image->data[i];
		image->data[i] = image->data[i + 2];
		image->data[i + 2] = temp;
	}
	return 1;
}

/*
 *  -------------------------------------------------------
	Loads a texture

	Function provided by Dr. Fan in A4 help
    -------------------------------------------------------
    Preconditions:  pointer to filename string

    Postconditions: loads a previously opened image struct in classic C style!
    -------------------------------------------------------
 */
Image* loadTexture(char *filename) {
	Image *image1;
	image1 = (Image *) malloc(sizeof(Image));
	if (image1 == NULL) {
		printf("Error allocating space for image");
		exit(0);
	}
	if (!ImageLoad(filename, image1)) {
		exit(1);
	}
	return image1;
}

void KeyboardFunction(GLubyte key, int x, int y) {

	GLint colorOfRemovedBlock;
	GLint currentPaddleLane = myPaddle.lanePosition;

	if(key == 'x'){
		colorOfRemovedBlock = myPaddle.dumpPaddle();

		if(colorOfRemovedBlock != -1){
			myGameArea.insertNewBlock(currentPaddleLane, colorOfRemovedBlock);
		}
	}

	glutPostRedisplay();
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
	glutPostRedisplay();
}

void updateGameplay(void){

	GLint result;
	bool gameAreaFull;

	result = myGameArea.checkVerticalKlax();

	if (result != -1) {
		PlaySound((LPCSTR) "sounds/klaxSound.wav", NULL, SND_FILENAME | SND_ASYNC);
		myGameArea.breakDownVerticalKlax(result);
		myScore.addKlaxToScore();
	}

	result = myGameArea.checkHorizontalKlax();

	if(result != -1){
		PlaySound((LPCSTR) "sounds/klaxSound.wav", NULL, SND_FILENAME | SND_ASYNC);
		myGameArea.breakDownHorizontalKlax(result);
		myScore.addKlaxToScore();
	}

	result = myGameArea.checkLeftDiagonalKlax();

	if(result != -1){
		PlaySound((LPCSTR) "sounds/klaxSound.wav", NULL, SND_FILENAME | SND_ASYNC);
		myGameArea.breakDownLeftDiagonalKlax();
		myScore.addKlaxToScore();
	}

	result = myGameArea.checkRightDiagonalKlax();

	if(result != -1){
		PlaySound((LPCSTR) "sounds/klaxSound.wav", NULL, SND_FILENAME | SND_ASYNC);
		myGameArea.breakDownRightDiagonalKlax();
		myScore.addKlaxToScore();
	}

	gameAreaFull = myGameArea.checkGameAreaFull();
	if(gameAreaFull){
		myGameArea.reset();
	}
}

void ConveyorSound(void){
	if(conveyorSound == 0)
		{
			PlaySound((LPCSTR) "sounds/conveyorMovement1.wav", NULL, SND_FILENAME | SND_ASYNC);
			conveyorSound = 1;
		}
		else{
			PlaySound((LPCSTR) "sounds/conveyorMovement2.wav", NULL, SND_FILENAME | SND_ASYNC);
			conveyorSound = 0;
		}
}

void DisplayFunction(void)
{
	numDisplayFunctionIterations++;

	PasteBackground();
	GameViewInit();

	updateGameplay();
	myGameArea.draw();
	myConveyorBelt.draw();
	myPaddle.draw();
	myScore.draw();

	ConveyorSound();
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

	glEnable(GL_TEXTURE_2D);
	jupiter.draw();
	neptune.draw();
	glDisable(GL_TEXTURE_2D);

	glFlush();
	glutSwapBuffers();

	Sleep(conveyorBeltDelay);
}

void TextureInit(void){

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// Create two texture
	glGenTextures(3, textures);

	// configure and load first planet
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //scale linearly when image smalled than texture
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	Image* image1 = loadTexture("textures/jupiter.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);

	jupiter.textureNum = textures[0];
	gluQuadricDrawStyle(jupiter.sphere, GLU_FILL);
	gluQuadricTexture(jupiter.sphere, GL_TRUE);
	gluQuadricNormals(jupiter.sphere, GLU_SMOOTH);
	glShadeModel(GL_FLAT);

	jupiter.translate(1.5,1.5,-1);

	// configure and load second planet
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //scale linearly when image smalled than texture
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	Image* image2 = loadTexture("textures/neptune.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);

	neptune.textureNum = textures[1];
	gluQuadricDrawStyle(neptune.sphere, GLU_FILL);
	gluQuadricTexture(neptune.sphere, GL_TRUE);
	gluQuadricNormals(neptune.sphere, GLU_SMOOTH);
	glShadeModel(GL_FLAT);

	neptune.translate(-1.5, 2, -2);

	//configure background texture
	glBindTexture( GL_TEXTURE_2D, textures[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //scale linearly when image smalled than texture
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	Image* image3 = loadTexture("textures/space.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image3->sizeX, image3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image3->data);
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_FLAT);

	glDisable(GL_DEPTH_TEST);

	PasteBackground();
}

void PasteBackground(void) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1, 1, 0);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(0, 0);
	glTexCoord2f(1, 0);
	glVertex2f(1, 0);
	glTexCoord2f(1, 1);
	glVertex2f(1, 1);
	glTexCoord2f(0, 1);
	glVertex2f(0, 1);
	glEnd();

	glutSwapBuffers();

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(0, 0);
	glTexCoord2f(1, 0);
	glVertex2f(1, 0);
	glTexCoord2f(1, 1);
	glVertex2f(1, 1);
	glTexCoord2f(0, 1);
	glVertex2f(0, 1);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void GameViewInit(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(vangle, 1.0, dnear, dfar);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(myCamera.viewPositon.x, myCamera.viewPositon.y,
			myCamera.viewPositon.z, myCamera.rotationPoint.x,
			myCamera.rotationPoint.y, myCamera.rotationPoint.z,
			myCamera.viewUpDirection.x, myCamera.viewUpDirection.y,
			myCamera.viewUpDirection.z);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(windowPositionX, windowPositionY);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Klax (By Tom LaMantia)");

	TextureInit();
	GameViewInit();
	glutDisplayFunc(DisplayFunction);
	glutKeyboardFunc(KeyboardFunction);
	glutSpecialFunc(KeyboardPaddleControl);

	/* Do it */
	glutMainLoop();

	return 0;
}
