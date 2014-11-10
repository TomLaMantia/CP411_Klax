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
    This file contains implementation for the GameArea class,
    which is defined in GameArea.hpp
    -------------------------------------------------------
 */

#include"GameArea.hpp"

GameArea :: GameArea()
{
	gameAreaMatrix[0][0] = 1; gameAreaMatrix[0][1] = 0; gameAreaMatrix[0][2] = 0;
	gameAreaMatrix[1][0] = 1; gameAreaMatrix[1][1] = 1; gameAreaMatrix[1][2] = 1;
	gameAreaMatrix[2][0] = 1; gameAreaMatrix[2][1] = 2; gameAreaMatrix[2][2] = 1;
}

GLint GameArea :: checkDiagonalKlax()
{
	GLint result = -1;

	if(this->gameAreaMatrix[0][0] == this->gameAreaMatrix[1][1] &&
			this->gameAreaMatrix[1][1] == this->gameAreaMatrix[2][2])
	{
		result = 0;
	}

	return result;
}

GLint GameArea :: checkHorizontalKlax()
{
	GLint row = 0;
	GLint result = -1;
	bool foundKlax = false;

	while(row < 3 && foundKlax == false){
		if (this->gameAreaMatrix[row][0] == this->gameAreaMatrix[row][1] &&
				this->gameAreaMatrix[row][1] == this->gameAreaMatrix[row][2])
		{
			foundKlax = true;
		}

		row++;
	}

	if(foundKlax == true)
	{
		result = row;
	}

	return result;


}

GLint GameArea :: checkVerticalKlax()
{
	GLint col = 0;
	GLint result = -1;
	bool foundKlax = false;

	while(col < 3 && foundKlax == false){
		if (this->gameAreaMatrix[0][col] == this->gameAreaMatrix[1][col] &&
				this->gameAreaMatrix[1][col] == this->gameAreaMatrix[2][col])
		{
			foundKlax = true;
		}

		col++;
	}

	if(foundKlax == true)
	{
		result = col;
	}

	return result;
}

void GameArea :: breakDownHorizontalKlax(GLint klaxRow)
{

}

void GameArea :: breakDownVerticalKlax(GLint klaxCol)
{
	this->gameAreaMatrix[0][klaxCol] = -1;
	this->gameAreaMatrix[1][klaxCol] = -1;
	this->gameAreaMatrix[2][klaxCol] = -1;
}


