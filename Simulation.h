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

#pragma once

#include "GroceryNode.h"

#include "GroceryList.h"

#include "Queue.h"


/********************************************************************************************************************
* Class name: Simulation
* Description: This Simulation class has methods for running the 24 hour simulation of a normal and an express customer lane
*              at a grocery store.
*********************************************************************************************************************/
class Simulation
{
public:
	Simulation();

	bool run_simulation();


private:

	

	int normal_lane;
	int express_lane;

	int arrival_time_normal_lane;
	int arrival_time_express_lane;
	int normal_customer_arrival_time;
	int express_customer_arrival_time;


	int first_customer_service_time_normal_lane;
	int first_customer_service_time_express_lane;

	int print_entire_queue_every_ten_mins;
};