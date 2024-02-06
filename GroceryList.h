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

#include <iostream>

#include <string>

#include "GroceryNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


/********************************************************************************************************************
* Class name: GroceryList
* Description: This GroceryList class manages how many groceries and what kind of groceries each customer carries in a lane.
*********************************************************************************************************************/
class GroceryList
{
public:
	GroceryList(int normal_or_express);
	~GroceryList();

	
	int get_how_many_groceries(); //extracts int how many!

	GroceryNode* get_pHead_grocery();

	bool insert_grocery_node();

	void print_each_grocery();

	
	

private:
	GroceryNode* pHead_grocery;
	int how_many;
};



std::ostream& operator <<(std::ostream& stream, GroceryList& grocery_list);

