/*
 -------------------------------------------------------
 Author: Tom LaMantia
 Id: 110283790
 Email: lama3790@mylaurier.ca
 Version: November 18, 2014
 -------------------------------------------------------
 */

/*
   -------------------------------------------------------
    This header file contains the definition for the Test Conveyor Belt class

    Implementations of these methods are contained in TestConveyorBelt.cpp
    -------------------------------------------------------
 */

#ifndef TESTCONVEYORBELT_HPP_
#define TESTCONVEYORBELT_HPP_
#include"BaseTest.hpp"
#include"ConveyorBelt.hpp"
#include"BlockNode.hpp"
#include"Block.hpp"
class TestConveyorBelt: public BaseTest{
public:
	TestConveyorBelt();
	ConveyorBelt conveyor;
	void testMoveConveyor();
	void testInsertBlockOnConveyor();
	void testRemoveBlockFromConveyor();
	void setUp();
	void tearDown();
	void testSuite();
};




#endif /* TESTCONVEYORBELT_HPP_ */
