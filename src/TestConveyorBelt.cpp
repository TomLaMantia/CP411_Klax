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

#include"TestConveyorBelt.hpp"

TestConveyorBelt :: TestConveyorBelt(){
	this->conveyor = new ConveyorBelt();
}

void TestConveyorBelt :: testInsertBlockOnConveyor(){
	this->conveyor->insertBlockOnConveyor();
	int result = this->conveyor->blockList.getListSize();
	this->assert(result == 1, true, "No block was added");
	// check the block
	BlockNode *block_result = this->conveyor->blockList.returnIndex(0);
	GLint position = block_result->position;
	GLint lane = block_result->lane;
	this->assert(10 == position, true,
				"Block Position not added properly");
	this->assert(lane <= 2, true,
				"Block Lane not added properly");
}

void TestConveyorBelt :: testRemoveBlockFromConveyor(){
	// test removed with blocks
	LinkedList *removedNodes;
	removedNodes = this->conveyor->removeBlockFromConveyor();
	int size = this->conveyor->blockList.getListSize();
	this->assert(size, 0, "Block was not removed");
	this->assert(removedNodes->getListSize(), 0,
				"List of Nodes removed: not zero");
	// add a block
	BlockNode newBlock = BlockNode();
	newBlock.position = 0;
	this->conveyor->blockList.listInsertRear(&newBlock);
	removedNodes = this->conveyor->removeBlockFromConveyor();
	size = this->conveyor->blockList.getListSize();
	this->assert(size, 0, "Block was not removed");
	this->assert(removedNodes->getListSize(), 1,
				"List of Nodes removed: was not one");
}

void TestConveyorBelt :: testMoveConveyor(){
	// make sure it works on empty list
	this->conveyor->moveConveyor();
	// add a block
	BlockNode newBlock = BlockNode();
	newBlock.position = 10;
	this->conveyor->blockList.listInsertRear(&newBlock);
	this->conveyor->moveConveyor();
	BlockNode *block_result = this->conveyor->blockList.returnIndex(0);
	this->assert(block_result->position, 9, "Block was not moved towards zero");
}

void TestConveyorBelt :: setUp(){
	this->conveyor = new ConveyorBelt();
}

void TestConveyorBelt :: tearDown(){
	delete &conveyor;
}

void run(void (TestConveyorBelt :: *test)(void), TestConveyorBelt * tester){
	try{
		tester->setUp();
		(tester->*test)();
		tester->tearDown();
	}catch (int e){
		cout << "Exception: " << e;
	}
}

void TestConveyorBelt :: testSuite(){
	cout << "Testing Conveyor Belt\n";
	cout << "------------------------------\n";
	try{
	run(&TestConveyorBelt::testInsertBlockOnConveyor, this);
	run(&TestConveyorBelt::testMoveConveyor, this);
	run(&TestConveyorBelt::testRemoveBlockFromConveyor, this);
	}catch (int e){
		cout << "Error\n";
	}
	cout << "------------------------------\n";
	cout << "Finished Testing Conveyor Belt\n";
	this->stats();
}

