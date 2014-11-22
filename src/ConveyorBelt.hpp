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
    This header file contains the definition for the conveyor
    belt class which extents the shape class.

    Implementations of these methods are contained in ConveyorBelt.cpp
    -------------------------------------------------------
 */

#ifndef CCONVEYORBELT_H
#define CCONVEYORBELT_H

#include"LinkedList.hpp"
#include"Block.hpp"
#include<stdlib.h>
#include<time.h>

class ConveyorBelt{
	public:
		LinkedList blockList;
		ConveyorBelt();
		void insertBlockOnConveyor();
		LinkedList* removeBlockFromConveyor();
		void moveConveyor();
		void draw();
};
#endif
