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
    This file contains implementation for the Test class,
    which is defined in Test.hpp
    -------------------------------------------------------
 */
#include "BaseTest.hpp"

BaseTest :: BaseTest(){
}

BaseTest :: ~BaseTest(){

}

void BaseTest :: setUp(){

}

void BaseTest :: tearDown(){

}

/*
   -------------------------------------------------------
    This function checks if the two conditions are equal
    If they are not equal prints out the error message
    -------------------------------------------------------
    Preconditions:
    	cond1: the first condition (boolean)
    	cond2: the second condition (boolean)
    	message: the error message (char array)
    Postconditions:
    	prints message if conditions are not met
    -------------------------------------------------------
 */
void BaseTest :: assert(bool cond1, bool cond2, char * message){
	if (cond1 != cond2){
		cout << message << "\n";
	}
}
