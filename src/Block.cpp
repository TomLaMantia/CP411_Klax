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
    This file contains implementation for the Block class,
    which is defined in Block.hpp
    -------------------------------------------------------
 */

#include"Block.hpp"

Block :: Block()
{
	/* Specification of model co-ordinates */
	/* Verticies */
	vertex[0][0] = -1;vertex[0][1] = -1;vertex[0][2] = -1;
	vertex[1][0] = -1;vertex[1][1] = 1; vertex[1][2] = -1;
	vertex[2][0] = 1;vertex[2][1] = -1; vertex[2][2] = -1;
	vertex[3][0] = 1;vertex[3][1] = 1;vertex[3][2] = -1;
	vertex[4][0] = -1;vertex[4][1] = -1;vertex[4][2] = 1;
	vertex[5][0] = -1;vertex[5][1] = 1; vertex[5][2] = 1;
	vertex[6][0] = 1;vertex[6][1] = -1;vertex[6][2] = 1;
	vertex[7][0] = 1;vertex[7][1] = 1;vertex[7][2] = 1;

	/* Faces */
	face[0][0] = 0;face[0][1] = 1;face[0][2] = 3; face[0][3] = 2;
	face[1][0] = 3;face[1][1] = 7;face[1][2] = 6;face[1][3] = 2;
	face[2][0] = 7;face[2][1] = 5;face[2][2] = 4;face[2][3] = 6;
	face[3][0] = 4;face[3][1] = 5;face[3][2] = 1;face[3][3] = 0;
	face[4][0] = 5;face[4][1] = 7;face[4][2] = 3;face[4][3] = 1;
	face[5][0] = 6;face[5][1] = 4;face[5][2] = 0;face[5][3] = 2;

	this->colorCode = -1;
}

void Block :: drawFace(int i)
{
	glBegin(GL_POLYGON);
	glVertex3fv(&vertex[face[i][0]][0]);
	glVertex3fv(&vertex[face[i][1]][0]);
	glVertex3fv(&vertex[face[i][2]][0]);
	glVertex3fv(&vertex[face[i][3]][0]);
	glEnd();
}

void Block :: draw()
{
	if(this->colorCode != -1)
	{
		if(this->colorCode == 0)
			{
				glColor3f(1,0,1); //purple
			}
			else if(this->colorCode == 1)
			{
				glColor3f(1,0,0); //red
			}
			else if(this->colorCode == 2)
			{
				glColor3f(1, 0.5, 0); //orange
			}
			else if(this->colorCode == 3)
			{
				glColor3f(1, 1, 0); //yellow
			}

			glPushMatrix();
			this->ctmMultiply();

			glScalef(scaleFactor, scaleFactor, scaleFactor);
			for (int i = 0; i < 6; i++) {

					drawFace(i);
					glFlush();
					glutPostRedisplay();

			}
			glPopMatrix();
	}
}
