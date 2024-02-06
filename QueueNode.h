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

#include "Data.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;


/********************************************************************************************************************
* Class name: QueueNode
* Description: This QueueNode class represents each QueueNode that is placed in queue data structure for either a normal
*              lane or an express lane. This node has a pointer to Data class object and a pointer to a Queuenode class.
*********************************************************************************************************************/
class QueueNode
{
public: // Member functions

	QueueNode();

	~QueueNode();
	
	Data* get_pData();
	void set_pData(Data* const new_pData);

	QueueNode* get_pNext();
	void set_pNext(QueueNode* const new_pNext);


	//make a new niode for queue
	//QueueNode* make_queue_node(int lane, Queue& customer_lane, Data customerNumber);
	

private:
	Data* pData; // The memory for Data will need to be allocated on the heap as well!
	QueueNode* pNext;
};