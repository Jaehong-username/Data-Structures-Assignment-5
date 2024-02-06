#include "test.h"


/********************************************************************************************************************
* Function: test_enqueue()
* Description: checks for whether or not enqueue function works correctly.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Test::test_enqueue()
{
	//Queue customer_lane_queue; //this needs to go to the private member!!!

	int normal_lane = 0;

	Data* pData_created = new Data(normal_lane /*customer_lane_queue.calculate_total_time()*/);
	QueueNode* pMem = new QueueNode;
	bool success = customer_lane_queue.enqueue(0, customer_lane_queue, pData_created, pMem);

	if (success == false)
	{
		cout << "Test for enqueuing a node failed!\n" << endl;
	}

	else
	{
		cout << "Test for enqueuing a node successed!\n" << endl;
	}

}


/********************************************************************************************************************
* Function: test_dequeue()
* Description: checks for whether or not dequeue function works correctly.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Test::test_dequeue()
{
	//Queue customer_lane; //this needs to go to the private member!!!

	bool success = customer_lane_queue.dequeue();

	if (success == false)
	{
		cout << "Test for dequeuing a node failed!\n" << endl;
	}

	else
	{
		cout << "Test for dequeuing a node successed!\n" << endl;
	}
}


/********************************************************************************************************************
* Function: test_simulation_24hours()
* Description: checks for whether or not 24 hour simulation of customers lane at a grocery store works correctly.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Test::test_simulation_24hours()
{
	Simulation simulation;
	bool success = simulation.run_simulation();

	if (success = true) cout << "\n\n24 hour normal/express queue simulation test succeeded!\n" << endl;

	else cout << "\n\n24 hour normal/express queue simulation test failed!\n" << endl;

}


/********************************************************************************************************************
* Function: run_test()
* Description: Runs the test by calling each test function.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Test::run_test()
{

	cout << "Test 1: Enqueuing a node on an empty queue\n" << endl;
	test_enqueue();

	cout << "Test 2: Enqueuing a node with one node in the queue\n" << endl;
	test_enqueue();

	cout << "Test 3: Dequeuing a node from the two nodes already existing in the queue\n" << endl;
	test_dequeue();

	cout << "Test 4: Dequeuing a node from one remaining node in the queue\n" << endl;
	test_dequeue();

	cout << "Final test: Running a 24 hour normal/express lane simulation\n" << endl;
	test_simulation_24hours();
}


