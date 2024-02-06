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

#include "QueueNode.h";

using std::cin;
using std::cout;
using std::endl;
using std::string;

/********************************************************************************************************************
* Class name: Queue
* Description: This Queue class represents a queue data structure of customers waiting in line.
*********************************************************************************************************************/
class Queue
{
public: // Member functions

	Queue() {};//created an empty constructor
	//Queue(Queue& copy);
	~Queue() {};

	//getter and setter for private members
	QueueNode* get_pHead();
	void set_pHead(QueueNode* new_pHead);

	QueueNode* get_pTail();
	void set_pTail(QueueNode* new_pTail);

	//queue related functions
	bool isEmpty();
	void printQueue();

	bool enqueue(int lane, Queue customer_lane, Data* pData_created, QueueNode* pMem); //when inserting function invoked! maybe also call calculate
	bool dequeue();

	int calculate_total_time();

private: //private members are pHead pointer, pTail pointer to QueueNode class
	QueueNode* pHead;
	QueueNode* pTail;
};
