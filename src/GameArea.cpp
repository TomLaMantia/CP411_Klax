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
	gameAreaMatrix[0][0] = -1; gameAreaMatrix[0][1] = -2; gameAreaMatrix[0][2] = -1;
	gameAreaMatrix[1][0] = -1; gameAreaMatrix[1][1] = -1; gameAreaMatrix[1][2] = -1;
	gameAreaMatrix[2][0] = 3; gameAreaMatrix[2][1] = 3; gameAreaMatrix[2][2] = 3;
}

void GameArea :: printGameAreaTest()
{
	int row, col;

	for(row = 0; row < 3; row++)
	{
		for(col = 0; col < 3; col++)
		{
			cout << this->gameAreaMatrix[row][col] << " ";
 		}

		cout << endl;
	}
}

GLint GameArea :: checkDiagonalKlax()
{
	GLint result = -1;

	if(this->gameAreaMatrix[0][0] == this->gameAreaMatrix[1][1] &&
			this->gameAreaMatrix[1][1] == this->gameAreaMatrix[2][2] && this->gameAreaMatrix[0][0] != -1)
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
				this->gameAreaMatrix[row][1] == this->gameAreaMatrix[row][2] && this->gameAreaMatrix[row][0] != -1)
		{
			foundKlax = true;
			result = row;
		}

		row++;
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
				this->gameAreaMatrix[1][col] == this->gameAreaMatrix[2][col] && this->gameAreaMatrix[0][col] != -1)
		{
			foundKlax = true;
			result = col;
		}

		col++;
	}

	return result;
}

bool GameArea :: insertNewBlock(GLint colNumber, Block newBlock)
{
	bool blockInserted = false;
	GLint i = 2;

	if(this->gameAreaMatrix[0][colNumber] != -1)
	{
		while(i >= 0 && blockInserted == false)
		{
			if(this->gameAreaMatrix[i][colNumber] != -1)
			{
				this->gameAreaMatrix[i][colNumber] = 1; //ie put the shape in!
				blockInserted = true;
			}
			i++;
		}
	}

	return blockInserted;
}

void GameArea :: breakDownDiagonalKlax()
{
	this->gameAreaMatrix[0][0] = -1;

	this->gameAreaMatrix[1][1] = this->gameAreaMatrix[0][1];
	this->gameAreaMatrix[0][1] = -1;

	this->gameAreaMatrix[2][2] = this->gameAreaMatrix[1][2];
	this->gameAreaMatrix[1][2] = this->gameAreaMatrix[0][2];
	this->gameAreaMatrix[0][2] = -1;
}

void GameArea :: breakDownHorizontalKlax(GLint klaxRow)
{
	GLint rowIndex, colIndex;

	for(colIndex = 0; colIndex < 3; colIndex++)
	{
		rowIndex = klaxRow;
		while(rowIndex > 0)
		{
			this->gameAreaMatrix[rowIndex][colIndex] = this->gameAreaMatrix[rowIndex - 1][colIndex];
			rowIndex--;
		}

		this->gameAreaMatrix[0][colIndex] = -1;
	}
}

void GameArea :: breakDownVerticalKlax(GLint klaxCol)
{
	this->gameAreaMatrix[0][klaxCol] = -1;
	this->gameAreaMatrix[1][klaxCol] = -1;
	this->gameAreaMatrix[2][klaxCol] = -1;
}


