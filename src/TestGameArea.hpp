/*
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
    This header file contains the definition for the Tests of the Game Area class

    Implementations of these methods are contained in TestGameArea.cpp
    -------------------------------------------------------
 */
#ifndef TESTGAMEAREA_HPP_
#define TESTGAMEAREA_HPP_
#include"BaseTest.hpp"
#include"GameArea.hpp"
#include"BlockNode.hpp"
#include"Block.hpp"
class TestGameArea: public BaseTest{
	public:
		TestGameArea();
		~TestGameArea();
		GameArea *game;
		void testCheckHorizontalKlax();
		void testReset();
		void testCheckDiagonalKlax();
		void testCheckVerticalKlax();
		void testBreakDownVerticalKlax();
		void testBreakDownHorizontalKlax();
		void testBreakDownDiagonalKlax();
		void setUp();
		void tearDown();
		void testSuite();
};
#endif /* TESTGAMEAREA_HPP_ */
