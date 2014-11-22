/*
 -------------------------------------------------------
 Author: Tom LaMantia
 Id: 110283790
 Email: lama3790@mylaurier.ca
 Version: 2014 M11 18
 -------------------------------------------------------
 */

/*
   -------------------------------------------------------
    This file contains the tests for the ConveyorBelt

    Implementations of these methods are contained in TestConveyorBelt.hpp
    -------------------------------------------------------
 */
#include"TestGameArea.hpp"
TestGameArea :: TestGameArea(){
	this->game = new GameArea();
}

TestGameArea :: ~TestGameArea(){
	delete &this->game;
}
void TestGameArea :: setUp(){
	this->game = new GameArea();
}

void TestGameArea :: tearDown(){
	delete &this->game;
}

void TestGameArea :: testReset(){
	GLint before = 2;
	game->gameAreaMatrix[0][0].colorCode = before;
	game->reset();
	GLint after = game->gameAreaMatrix[0][0].colorCode;
	this->assert(before == after, false, "Did not reset color");
}

void TestGameArea :: testCheckHorizontalKlax(){
	GLint result;
	GLint expect = -1;
	result = game->checkHorizontalKlax();
	this->assert(result == expect, true,
			"Found a horizontal klax on fresh board");
	game->gameAreaMatrix[0][0].colorCode = 0;
	game->gameAreaMatrix[0][1].colorCode = 1;
	game->gameAreaMatrix[0][2].colorCode = 2;
	result = game->checkHorizontalKlax();
	this->assert(result == expect, true,
				"Found a horizontal on non-klax");
	game->gameAreaMatrix[1][0].colorCode = 0;
	game->gameAreaMatrix[1][1].colorCode = 0;
	game->gameAreaMatrix[1][2].colorCode = 0;
	result = game->checkHorizontalKlax();
	this->assert(result == expect, false,
				"Failed to find horizontal klax");
	GLint found = 1;
	this->assert(result == found, true,
				"Found klax on wrong row");
}

void TestGameArea :: testCheckVerticalKlax(){
	GLint result;
	GLint expect = -1;
	result = game->checkVerticalKlax();
	this->assert(result == expect, true,
			"Found a vertical klax on fresh board");
	game->gameAreaMatrix[0][0].colorCode = 0;
	game->gameAreaMatrix[1][0].colorCode = 1;
	game->gameAreaMatrix[2][0].colorCode = 2;
	result = game->checkVerticalKlax();
	this->assert(result == expect, true,
				"Found a vertical on non-klax");
	game->gameAreaMatrix[0][1].colorCode = 0;
	game->gameAreaMatrix[1][1].colorCode = 0;
	game->gameAreaMatrix[2][1].colorCode = 0;
	result = game->checkVerticalKlax();
	this->assert(result == expect, false,
				"Failed to find verical klax");
	GLint found = 1;
	this->assert(result == found, true,
				"Found klax on wrong column");
}

void TestGameArea :: testCheckDiagonalKlax(){
	GLint result;
	GLint expect = -1;
	result = game->checkDiagonalKlax();
	this->assert(result == expect, true,
			"Found a diagonal klax on fresh board");
	game->gameAreaMatrix[0][0].colorCode = 0;
	game->gameAreaMatrix[1][1].colorCode = 1;
	game->gameAreaMatrix[2][2].colorCode = 2;
	result = game->checkVerticalKlax();
	this->assert(result == expect, true,
				"Found a diagonal on non-klax");
	// a left to right diagonal
	game->gameAreaMatrix[0][0].colorCode = 0;
	game->gameAreaMatrix[1][1].colorCode = 0;
	game->gameAreaMatrix[2][2].colorCode = 0;
	result = game->checkVerticalKlax();
	this->assert(result == expect, false,
				"Failed to find left diagonal klax");
	GLint found = 0;
	this->assert(result == found, true,
				"Found klax on wrong diagonal");
	// right to left diagonal
	game->gameAreaMatrix[0][0].colorCode = 0;
	game->gameAreaMatrix[2][2].colorCode = 2;
	game->gameAreaMatrix[1][1].colorCode = 1;
	game->gameAreaMatrix[0][2].colorCode = 1;
	game->gameAreaMatrix[2][0].colorCode = 1;
	result = game->checkVerticalKlax();
	this->assert(result == expect, false,
				"Failed to find right diagonal klax");
	found = 0;
	this->assert(result == found, true,
				"Found klax on wrong diagonal");
}

void TestGameArea :: testBreakDownHorizontalKlax(){

}

void TestGameArea :: testBreakDownVerticalKlax(){

}

void TestGameArea :: testBreakDownDiagonalKlax(){

}

void run(void (TestGameArea :: *test)(void), TestGameArea * tester){
	try{
		tester->setUp();
		(tester->*test)();
		tester->tearDown();
	}catch (int e){
		cout << "Exception: " << e;
	}
}


void TestGameArea ::  testSuite(){
	cout << "Testing Game Area\n";
	cout << "------------------------------\n";
	try{
		run(&TestGameArea::testReset, this);
		run(&TestGameArea::testCheckHorizontalKlax, this);
		run(&TestGameArea::testCheckVerticalKlax, this);
		run(&TestGameArea::testCheckDiagonalKlax, this);
		run(&TestGameArea::testBreakDownHorizontalKlax, this);
		run(&TestGameArea::testBreakDownVerticalKlax, this);
		run(&TestGameArea::testBreakDownDiagonalKlax, this);
	}catch (int e){
		cout << "Error\n";
	}
	cout << "------------------------------\n";
	cout << "Finished Testing Conveyor Belt\n";
	this->stats();
}

