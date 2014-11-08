/*
 -------------------------------------------------------
 Author: Tom LaMantia
 Id: 110283790
 Email: lama3790@mylaurier.ca
 Version: December 1, 2014
 -------------------------------------------------------
 */

#include"matrix.hpp"
#include<iostream>
/*
 -------------------------------------------------------
 Constructs the identity matrix
 -------------------------------------------------------
 Preconditions:
 none
 Postconditions:
 mat = 4x4 identity matrix
 -------------------------------------------------------
 */
Matrix::Matrix() {
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (i == j) {
				mat[i][j] = 1;
			} else {
				mat[i][j] = 0;
			}
		}
	}
}

/*
 -------------------------------------------------------
 Matrix multiplication method
 -------------------------------------------------------
 Preconditions:
 Matrix *m - a pointer to a matrix object
 Postconditions:
 mat = m * mat
 -------------------------------------------------------
 */
void Matrix::matrixPreMultiply(Matrix *m) {
	Matrix *temp = new Matrix();
	int row, col, k;
	GLfloat sum;

	for (row = 0; row < 4; row++) {

		for (col = 0; col < 4; col++) {
			sum = 0;

			for (k = 0; k < 4; k++) {
				sum += m->mat[row][k] * this->mat[k][col];
			}
			temp->mat[row][col] = sum;
		}
	}

	for (row = 0; row < 4; row++) {
		for (col = 0; col < 4; col++) {
			this->mat[row][col] = temp->mat[row][col];
		}
	}
	delete temp;
}

/*
 -------------------------------------------------------
 Matrix translation method
 -------------------------------------------------------
 Preconditions:
 	GLfloat tX, tY, tZ - transformation parameters
 Postconditions:
 	 Adds these parameters to the last column of the matrix
 	 to apply the transformation as specified for a homogeneous
 	 system (outlined in lecture).
 -------------------------------------------------------
 */
void Matrix::translate(GLfloat tX, GLfloat tY, GLfloat tZ) {
	mat[0][3] += tX;
	mat[1][3] += tY;
	mat[2][3] += tZ;
	mat[3][3] = 1;
}

/*
 -------------------------------------------------------
 Matrix transposition function
 -------------------------------------------------------
 Preconditions:
 	Void
 Postconditions:
 	 Transposes the main matrix of the calling shape
 -------------------------------------------------------
 */
void Matrix::transpose() {
	int row, col;
	Matrix *temp = new Matrix();

	for (row = 0; row < 3; row++) {
		for (col = 0; col < 3; col++)
			temp->mat[row][col] = this->mat[row][col];
	}

	for (row = 0; row < 3; row++) {
		for (col = 0; col < 3; col++) {
			temp->mat[row][col] = this->mat[col][row];
		}
	}
}

/*
 -------------------------------------------------------
 Matrix normalization routine
 -------------------------------------------------------
 Preconditions:
 	Void
 Postconditions:
 	 Normalizes the main matrix of the calling shape
 -------------------------------------------------------
 */
void Matrix::normalize() {
	GLfloat norm;

	norm = sqrt(
			this->mat[0][0] * this->mat[0][0]
					+ this->mat[1][0] * this->mat[1][0]
					+ this->mat[2][0] * this->mat[2][0]);

	this->mat[0][0] = this->mat[0][0] / norm;
	this->mat[1][0] = this->mat[1][0] / norm;
	this->mat[2][0] = this->mat[2][0] / norm;

	this->mat[0][2] = this->mat[1][0] * this->mat[2][1]
			- this->mat[2][0] * this->mat[1][1];
	this->mat[1][2] = this->mat[2][0] * this->mat[0][1]
			- this->mat[0][0] * this->mat[2][1];
	this->mat[2][2] = this->mat[0][0] * this->mat[1][1]
			- this->mat[1][0] * this->mat[0][1];

	norm = sqrt(
			this->mat[0][2] * this->mat[0][2]
					+ this->mat[1][2] * this->mat[1][2]
					+ this->mat[2][2] * this->mat[2][2]);

	this->mat[0][2] = this->mat[0][2] / norm;
	this->mat[1][2] = this->mat[1][2] / norm;
	this->mat[2][2] = this->mat[2][2] / norm;

	this->mat[0][1] = this->mat[1][2] * this->mat[2][0]
			- this->mat[1][0] * this->mat[2][2];
	this->mat[1][1] = this->mat[2][2] * this->mat[0][0]
			- this->mat[2][0] * this->mat[0][2];
	this->mat[2][1] = this->mat[0][2] * this->mat[1][0]
			- this->mat[0][0] * this->mat[1][2];

	this->mat[3][0] = 0;
	this->mat[3][1] = 0;
	this->mat[3][2] = 0;
	this->mat[3][3] = 1;
}

/*
 -------------------------------------------------------
 Vector Matrix multiplication method (code supplied in help file by Dr.Fan)
 -------------------------------------------------------
 Preconditions:
 	GLfloat *v - a pointer to an array of GLfloats which
 	define a vector object
 Postconditions:
 	 Multiplies the matrix of the calling shape with the
 	 vector pointed by *v
 -------------------------------------------------------
 */
void Matrix::multiplyVector(GLfloat *v) {

	int row, col, i;
	GLfloat sum;

	GLfloat temp[4];

	for (row = 0; row < 4; row++) {
		sum = 0;

		for (col = 0; col < 4; col++) {
			sum += this->mat[row][col] * v[col];
		}

		temp[row] = sum;
	}

	for (i = 0; i < 4; i++)
		v[i] = temp[i];

}

/*
 -------------------------------------------------------
	Matrix rotation method (code supplied in help file by Dr.Fan)
 -------------------------------------------------------
 Preconditions:
 	GLfloat x, y, z - co-ordinates specified by the matrix
 	GLfloat angle - the angle to rotate by
 Postconditions:
 	 Constructs a rotation matrix (as derived in lecture) and
 	 applies this rotation by composing it with the calling shape's
 	 main matrix using matrixPreMultiply as a helper method
 -------------------------------------------------------
 */
void Matrix::rotate(GLfloat x, GLfloat y, GLfloat z, GLfloat angle) {

	angle = angle * 3.1415926 / 180;
	float oneC = 1 - cos(angle);
	float COS = cos(angle);
	float SIN = sin(angle);

	Matrix* m = new Matrix();

	m->mat[0][0] = x * x * oneC + cos(angle);
	m->mat[0][1] = y * x * oneC + z * sin(angle);
	m->mat[0][2] = x * z * oneC - y * SIN;
	m->mat[0][3] = 0;
	m->mat[1][0] = x * y * oneC - z * SIN;
	m->mat[1][1] = y * y * oneC + COS;
	m->mat[1][2] = y * z * oneC + x * SIN;
	m->mat[1][3] = 0;
	m->mat[2][0] = x * z * oneC + y * SIN;
	m->mat[2][1] = y * z * oneC - x * SIN;
	m->mat[2][2] = z * z * oneC + COS;
	m->mat[2][3] = 0;
	m->mat[3][0] = 0;
	m->mat[3][1] = 0;
	m->mat[3][2] = 0;
	m->mat[3][3] = 1;

	this->matrixPreMultiply(m);
	delete m;
}

