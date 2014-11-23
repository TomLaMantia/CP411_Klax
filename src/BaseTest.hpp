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
    This header file contains the definition for the Test class

    Implementations of these methods are contained in Test.cpp
    -------------------------------------------------------
 */

#ifndef BASETEST_HPP_
#define BASETEST_HPP_
#include"ConveyorBelt.hpp"
#include"GameArea.hpp"
#include<stdio.h>
class BaseTest{
	public:
		GLint passed;
		GLint failed;
		BaseTest();
		virtual ~BaseTest();
		void assert(bool, bool, char*);
		virtual void setUp();
		virtual void tearDown();
		void stats();
};
#endif /* TEST_HPP_ */
