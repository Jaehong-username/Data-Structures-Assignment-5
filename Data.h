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

#pragma once //make sure each.h once if we included multiple times

#include <iostream>

#include <string>

#include "GroceryList.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


/********************************************************************************************************************
* Class name: Data
* Description: This Data class stores information for each customer: customer number, service time, totaltime, 
*              pHead_grocery_list.
*********************************************************************************************************************/
class Data
{
public: // Member functions

	//Data(int express_lane); //Data(0), Data(1), that is outside of the c++ class course.
	//Data(int normal_lane);
	
	Data(int lane);
	~Data();

	//make data memory node
	//Data* make_data_memory(int lane, Queue& customer_lane);
	
	int get_customerNumber();
	void set_customerNumber(const int new_customer_number);

	int get_servcieTime();
	void set_serviceTime(const int new_service_time);


	//int calculate_total_time(Queue lane);
	int get_totalTime();
	void set_totalTime(const int new_total_time);

	/*GroceryNode* get_pHead_grocery();
	void set_pHead_grocery(GroceryNode* new_pHead_grocery_created);*/

	GroceryList* get_pHead_grocery_list();
	void set_pHead_grocery_list(GroceryList* new_pHead_grocery_list_created);

	//static is a class member operating on the class itself
private:  //if I   static is a keyword variable for a class itself not for instances.
	/*static */int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
		int serviceTime; // Random time; varies between express and normal lanes; units in minutes   1-5  3-8
		int totalTime; // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
		//header pointer!!!
		//GroceryNode* pHead_grocery; //is just a pointer varaible called pNext to GroceryNode.

		GroceryList* pHead_grocery_list;
		//nothing related to the primary members of GroceryNode. even if they have the same name, they belong to a different class
		//so cannot get access
		//even if we take care of bonus instructions totalTime is now based on how many groceries items each customer stores

}; // This memory needs to be allocated on the heap!



//member function when need to operate related to the data class. members functi have access to privatemembers
//while non member cannot get access to private members. which I would consider a more dangerous. 

//non member function defined outside of the class. 
