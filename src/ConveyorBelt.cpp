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
    This file contains implementation for the ConveyorBelt class,
    which is defined in ConveyorBelt.hpp
    -------------------------------------------------------
 */

#include"ConveyorBelt.hpp"

ConveyorBelt :: ConveyorBelt()
{

}

void ConveyorBelt :: insertBlockOnConveyor(){

	BlockNode* newBlock;
	newBlock->position = 10;

	srand(time(NULL));
	newBlock->lane = rand() % 2;

	this->blockList.listInsertRear(newBlock);
}

/*
 *  -------------------------------------------------------
    This function removes a block at the end of the conveyor
    (if there is a block at the end)
    -------------------------------------------------------
    Preconditions: none
    Postconditions:
       This function returns a pointer to the blocknode containing
       a block which is at the end of the conveyor. This is a
       block node at position 0. Since blocks are added one at a time,
       only one block can be at the end. If no block is at the end,
       this function simply returns NULL.
    -------------------------------------------------------
 */
BlockNode* ConveyorBelt :: removeBlockFromConveyor(){

	BlockNode *result;
	GLint i;

	for(i = 0; i < this->blockList.getListSize(); i++)
	{
		result = this->blockList.returnIndex(i);

		if(result->position != 0)
		{
			result = NULL;
		}
	}

	return result;
}

/*
 *  -------------------------------------------------------
    This function moves (increments) the conveyor
    -------------------------------------------------------
    Preconditions: none
    Postconditions:
       This function increments the conveyor. It does this by
       subtracting 1 from the position of each block node to
       move it "closer" to zero.
    -------------------------------------------------------
 */
void ConveyorBelt :: moveConveyor(){

	GLint i;

	for(i = 0; i < this->blockList.getListSize(); i++){
		this->blockList.incrementBlockPositionAtIndex(i);
	}
}

void ConveyorBelt :: draw(){

}
