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
    This file contains implementation for the ViewingEye class,
    which is defined in ViewingEye.hpp
    -------------------------------------------------------
 */

#include"ViewingEye.hpp"

/* Constructor */
ViewingEye :: ViewingEye()
{
	this->aperture = 50;
	this->focalLength = 70;
	this->eyeSeperation = this->focalLength/20;

	this->viewPositon.x = 0.2;
	this->viewPositon.y = 3.0;
	this->viewPositon.z = 7.0;

	this->viewDirectionVector.x = -this->viewPositon.x;
	this->viewDirectionVector.y = -this->viewPositon.y;
	this->viewDirectionVector.z = -this->viewPositon.z;

	this->viewUpDirection.x = 0;
	this->viewUpDirection.y = 1;
	this->viewUpDirection.z = 0;

	this->rotationPoint.x = 0.0;
	this->rotationPoint.y = 0.0;
	this->rotationPoint.z = 0.0;

	this->screenHeight = 800;
	this->screenWidth = 800;
}

void ViewingEye :: translateEyePosition(GLfloat tx, GLfloat ty, GLfloat tz)
{
	this->viewPositon.x += tx;
	this->viewPositon.y += ty;
	this->viewPositon.z += tz;
}


/*
 -------------------------------------------------------
 Resets the view. This is called when the user resets the program
 -------------------------------------------------------
 Preconditions:
 	void
 Postconditions:
	Sets all paramerters to default (as was done during initial
	construction)
 -------------------------------------------------------
 */
void ViewingEye :: resetEye()
{
	this->aperture = 50;
	this->focalLength = 70;
	this->eyeSeperation = this->focalLength/20;

	this->viewPositon.x = 0.0;
	this->viewPositon.y = 3.0;
	this->viewPositon.z = 7.0;

	this->viewDirectionVector.x = -this->viewPositon.x;
	this->viewDirectionVector.y = -this->viewPositon.y;
	this->viewDirectionVector.z = -this->viewPositon.z;

	this->viewUpDirection.x = 0;
	this->viewUpDirection.y = 1;
	this->viewUpDirection.z = 0;

	this->rotationPoint.x = 0.0;
	this->rotationPoint.y = 0.0;
	this->rotationPoint.z = 0.0;

	this->screenHeight = 800;
	this->screenWidth = 800;
}

/*
 -------------------------------------------------------
 Increases the zoom of the view. Used for "angle" option
 -------------------------------------------------------
 Preconditions:
 	GLfloat zoomFactor - angle theta measured in mouse function * 0.2
 Postconditions:
	Increases zoom accordingly
 -------------------------------------------------------
 */
void ViewingEye :: increaseZoom(GLfloat zoomFactor)
{
	this->viewPositon.z += zoomFactor;
	this->viewPositon.y += zoomFactor;
	this->viewPositon.x += zoomFactor;
}

/*
 -------------------------------------------------------
 Decreases the zoom of the view. Used for "angle" option
 -------------------------------------------------------
 Preconditions:
 	GLfloat zoomFactor - angle theta measured in mouse function * 0.2
 Postconditions:
	Decreases zoom accordingly
 -------------------------------------------------------
 */
void ViewingEye :: decreaseZoom(GLfloat zoomFactor)
{
	this->viewPositon.z -= zoomFactor;
	this->viewPositon.y -= zoomFactor;
	this->viewPositon.x -= zoomFactor;
}

/*
 -------------------------------------------------------
 Viewing eye translation method
 -------------------------------------------------------
 Preconditions:
 	GLfloat tX, tY, tZ - transformation parameters
 Postconditions:
 	 Adds these parameters to the viewPosition point
 -------------------------------------------------------
 */
void ViewingEye :: translate(GLfloat tx, GLfloat ty, GLfloat tz)
{
	this->viewPositon.x += tx;
	this->viewPositon.y += ty;
	this->viewPositon.z += tz;
}

/*
 -------------------------------------------------------
 Rotate eye method. Note: rotating the shape in model coordinates
 and rotating the view is very similar, except the view, we change
 the position of the view point rather than the model. This method
 was recycled from the shape rotate origin provided by Dr. Fan.
 -------------------------------------------------------
 Preconditions:
 	GLfloat tX, tY, tZ - transformation parameters
 Postconditions:
 	 Adds these parameters to the viewPosition point
 -------------------------------------------------------
 */
void ViewingEye :: rotateViewingEye(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle)
{
	Matrix *m = new Matrix();
	m->rotate(rx, ry, rz, angle);
	GLfloat v[4];
	v[0] = this->viewPositon.x;
	v[1] = this->viewPositon.y;
	v[2] = this->viewPositon.z;
	v[3] = 1;
	m->multiplyVector(v);
	this->viewPositon.x = v[0];
	this->viewPositon.y = v[1];
	this->viewPositon.z = v[2];
	delete m;
}
