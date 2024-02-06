/****************************************************************************************************************************
* Programmer: Jaehong Lee
* Class: CPTs 122, Fall 2023; Lab Section 3 (Tuesday 1:30PM - 4:20PM)
* Programming Assignment: PA5
* Date: October 24, 2023
* Description: This PA assignment is to make a test program that runs a 24-hour simulation of both a normal and an express 
*              lane at a grocery store. A queue data structure is employed in this assignment (First-in-first-out), which
*              resembles an actual line of customers standing in waiting. This tests enqueue and dequeue member functions 
*               from Queue class twice for each. Finally, it tests for 24 hour simulation of a grocery store function. 
*			   If each function is implemented correctly, it will display a success message, otherwise a failure message.
****************************************************************************************************************************/

#include "Simulation.h"

#include "Test.h"

//circular referance? as if there are two instnaces
int main(void)
{
	srand(time(NULL));
	/*Simulation simulation;
	simulation.run_simulation();*/

	Test test;
	test.run_test();

	return 0;
}