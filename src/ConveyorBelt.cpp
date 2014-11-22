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

CONST GLint ZOFFSET = -3;
CONST GLfloat INCREMENT = 0.5;

ConveyorBelt :: ConveyorBelt()
{

}

void ConveyorBelt :: insertBlockOnConveyor(){

	BlockNode* newBlock = new BlockNode();
	newBlock->position = 10;
	srand(time(NULL));
	newBlock->lane = rand() % 3;
	newBlock->data.colorCode = rand() % 4;
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

	BlockNode *node;
	bool blockRemoved = false;
	GLint i;

	for(i = 0; i < (this->blockList.getListSize()); i++)
	{
		node = this->blockList.returnIndex(i);

		if(node->position == 1)
		{
			this->blockList.listRemoveIndex(i);
			blockRemoved = true;
		}
	}

	if(blockRemoved == false)
		node = NULL;

	return node;
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

	glLineWidth(3.0);

	/*
	 * Draw the conveyor positions
	 */
	GLint i;
	GLfloat conveyorPositionZIndex = ZOFFSET;
	BlockNode *thisBlockNode;
	Block thisBlock;

	glColor3f(1,1,0);

	for(i = 10; i > 0; i--){
		glBegin(GL_LINES);
			glVertex3f(-1, 0, conveyorPositionZIndex);
			glVertex3f(1,0 , conveyorPositionZIndex);
		glEnd();

		conveyorPositionZIndex += INCREMENT;
	}

	/*
	 * Draw the blocks on the conveyor
	 */
	for(i = 0; i < (this->blockList.getListSize()); i++){

		thisBlockNode = this->blockList.returnIndex(i);
		thisBlock = thisBlockNode->data;

		/* Draw block in correct lane */
		if(thisBlockNode->lane == 0)
		{
			thisBlock.translate(-0.5,0,0);
		}
		else if(thisBlockNode->lane == 1)
		{
			thisBlock.translate(0,0,0);
		}
		else if(thisBlockNode->lane == 2)
		{
			thisBlock.translate(0.5,0,0);
		}

		/* Draw block in correct position */
		thisBlock.translate(0,0, -2.5 + (10-thisBlockNode->position) * 0.5);
		thisBlock.draw();
	}
}
