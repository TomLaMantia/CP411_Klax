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
    This file contains implementation for the Shape class,
    which is defined in Shape.hpp
    -------------------------------------------------------
 */

#include"Shape.hpp"

/* Constructor */
Shape :: Shape()
{
	/* Main shape matrix - used in ctmMultiply to integrate transformations into
	 * OpenGL graphics pipeline. 4x4 identity matrix for x,y,z cords (homogeneous system)*/
	MC.mat[0][0] = 1.0; MC.mat[0][1] = 0.0; MC.mat[0][2] = 0.0; MC.mat[0][3] = 0.0;
	MC.mat[1][0] = 0.0; MC.mat[1][1] = 1.0; MC.mat[1][2] = 0.0; MC.mat[1][3] = 0.0;
	MC.mat[2][0] = 0.0; MC.mat[2][1] = 0.0; MC.mat[2][2] = 1.0; MC.mat[2][3] = 0.0;
	MC.mat[3][0] = 0.0; MC.mat[3][1] = 0.0; MC.mat[3][2] = 0.0; MC.mat[3][3] = 1.0;
	scaleFactor = .1;
}

/*
Resets the shape's default values. This is called when user resets the world.
 */
void Shape :: resetShape()
{
	MC.mat[0][0] = 1.0; MC.mat[0][1] = 0.0; MC.mat[0][2] = 0.0; MC.mat[0][3] = 0.0;
	MC.mat[1][0] = 0.0; MC.mat[1][1] = 1.0; MC.mat[1][2] = 0.0; MC.mat[1][3] = 0.0;
	MC.mat[2][0] = 0.0; MC.mat[2][1] = 0.0; MC.mat[2][2] = 1.0; MC.mat[2][3] = 0.0;
	MC.mat[3][0] = 0.0; MC.mat[3][1] = 0.0; MC.mat[3][2] = 0.0; MC.mat[3][3] = 1.0;
	scaleFactor = .1;
}

/* Return the main Matrix of calling shape */
Matrix Shape :: getMC() {
	return this->MC;
}

/* Translate a shape. Uses matrix translate as a helper function */
void Shape :: translate(GLfloat tX, GLfloat tY, GLfloat tZ) {
	MC.translate(tX, tY, tZ);
	MC.normalize();
}

/* Rotate a shape. uses matrix rotation as a helper function */
void Shape :: rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	MC.rotate(rx, ry, rz, angle);
	MC.normalize();
}

/* Rotate a shape about the origin. uses matrix rotation as a helper function */
void Shape :: rotateOrigin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	Matrix *m = new Matrix();
	m->rotate(rx, ry, rz, angle);
	GLfloat v[4];
	v[0] = MC.mat[0][3];
	v[1] = MC.mat[1][3];
	v[2] = MC.mat[2][3];
	v[3] = MC.mat[3][3];
	m->multiplyVector(v);
	MC.mat[0][3] = v[0];
	MC.mat[1][3] = v[1];
	MC.mat[2][3] = v[2];
	MC.mat[3][3] = v[3];
	delete m;
}

/*
 -------------------------------------------------------
 Rotate a shape. uses matrix rotation as a helper function
 -------------------------------------------------------
 Preconditions:
 	GLfloat rx, ry, rz - x,y,z coordinates to rotate
 	GLfloat angle - angle to rotate by
 Postconditions:
	Shape's calling matrix is rotates with given parameters
 -------------------------------------------------------
 */
void Shape::rotateMc(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {

	GLfloat xCapture, yCapture, zCapture;

	xCapture = this->MC.mat[0][3];
	yCapture = this->MC.mat[1][3];
	zCapture = this->MC.mat[2][3];

	this->rotate(rx, ry, rz, angle);

	this->MC.mat[0][3] = xCapture;
	this->MC.mat[1][3] = yCapture;
	this->MC.mat[2][3] = zCapture;

	this->MC.normalize();
}

/* This function updates the scale factor of the calling shape */
void Shape :: scaleChange(GLfloat x) {
	scaleFactor += x;
}

/*
 -------------------------------------------------------
 Multiplies shape`s main matrix by the top matrix on OpenGl
 matrix stack.
 -------------------------------------------------------
 Preconditions:
 	void
 Postconditions:
	Calling shape`s MC multiplied with current matrix stack
	matrix.
 -------------------------------------------------------
 */
void Shape :: ctmMultiply() {
	GLfloat M[16];
	M[0] = MC.mat[0][0];
	M[1] = MC.mat[1][0];
	M[2] = MC.mat[2][0];
	M[3] = 0;
	M[4] = MC.mat[0][1];
	M[5] = MC.mat[1][1];
	M[6] = MC.mat[2][1];
	M[7] = 0;
	M[8] = MC.mat[0][2];
	M[9] = MC.mat[1][2];
	M[10] = MC.mat[2][2];
	M[11] = 0;
	M[12] = MC.mat[0][3];
	M[13] = MC.mat[1][3];
	M[14] = MC.mat[2][3];
	M[15] = 1;
	glMultMatrixf(M);
}

