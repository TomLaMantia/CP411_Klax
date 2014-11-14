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
    This file contains implementation for the BlockNode class,
    which is defined in BlockNode.hpp
    -------------------------------------------------------
 */

#include"BlockNode.hpp"

BlockNode :: BlockNode(){

	this->data = NULL;
	this->next = NULL;
	this->lane = -1;
	this->position = 10;
}
