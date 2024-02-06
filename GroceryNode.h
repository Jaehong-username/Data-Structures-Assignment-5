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

#include <fstream>

#include <string>



using std::cin;
using std::cout;
using std::endl;
using std::string;


/********************************************************************************************************************
* Class name: GroceryNode
* Description: This GroceryNode class manages a single grocery item node that is placed in a single-linked list for 
*              each customer.
*********************************************************************************************************************/
class GroceryNode
{
	friend GroceryList; //is a friend with GroceryList class
public:
	GroceryNode();
	~GroceryNode();

	string get_grocery_item();
	
	GroceryNode* get_pNext();
	void set_pNext(GroceryNode* new_pNext);


private:
	int test = 0;
	string grocery_items_list[8] = { "apple", "banana", "peach", "milk", "egg", "noodle", "cereal", "chocholate" };
	string grocery_item;
	GroceryNode* pNext;

};

                           