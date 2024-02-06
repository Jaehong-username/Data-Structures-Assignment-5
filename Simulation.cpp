#include "Simulation.h"


/********************************************************************************************************************
* Function: Simulation()
* Description: a constructor from Simulation class: initializes private members of Simulation class.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
Simulation::Simulation() //default constructor!!!
{
	normal_lane = 0;
	express_lane = 1;

	arrival_time_normal_lane = rand() % 5 + 1;
	arrival_time_express_lane = rand() % 6 + 3;
	normal_customer_arrival_time = arrival_time_normal_lane;
	express_customer_arrival_time = arrival_time_express_lane;


	first_customer_service_time_normal_lane = 0;
	first_customer_service_time_express_lane = 0;

	print_entire_queue_every_ten_mins = 10;
}


/********************************************************************************************************************
* Function: run_simulation()
* Description: runs a 24 hour simulation of customers waiting in either a normal queue or an express queue.
* Input parameters: Nothing
* Returns: a boolean value
*********************************************************************************************************************/
bool Simulation::run_simulation()
{
	bool success = false;

	Queue normal_lane_queue; //must be defined here not on private members otherwise crashes
	Queue express_lane_queue;

	for (int min_elapsed = 0; min_elapsed < 14400; min_elapsed++) //incremented by 1 represent 1 mins of time eapsed
	{

		////////////////////////////enqueuing a new customer in the normal lane////////////////////////////////////
		if (arrival_time_normal_lane == 0)
		{
			cout << "A new customer arrived on a normal lane. Mins elapsed: " << min_elapsed << endl;

			Data* pData_created = new Data(normal_lane/*, normal_lane_queue.calculate_total_time()*/);
			GroceryList* pGroceryList_created = new GroceryList(normal_lane);
			pData_created->set_pHead_grocery_list(pGroceryList_created);
			QueueNode* pMem = new QueueNode;
			normal_lane_queue.enqueue(normal_lane, normal_lane_queue, pData_created, pMem); //populate a customer standing on a normal lane
			

			pData_created->set_serviceTime(pData_created->get_pHead_grocery_list()->get_how_many_groceries());
			pData_created->set_totalTime(normal_lane_queue.calculate_total_time()); //we need to calculate after enqueuing!!!

			if (normal_lane_queue.get_pHead() == normal_lane_queue.get_pTail())
			{
				first_customer_service_time_normal_lane = pData_created->get_servcieTime();
			}

			//let's print out basic info about this new customer!!
			cout << "Customer Number: " << pData_created->get_customerNumber() << endl;
			cout << "The number of groceries this customer has: " << pData_created->get_pHead_grocery_list()->get_how_many_groceries() << endl;
			//cout << "This customer's grocery List: " << pData_created->get_pHead_grocery_list()->print_each_grocery() << endl;
			cout << "This customer's grocery List: " << *pData_created->get_pHead_grocery_list() << endl; //here we need* to dereferance the pointer to an GroceryList class obj
			                   //becuase we need to pass an obj itself into the << overloaded function.
			                   //here I am returning pHead pointer to GroceryList obj which is the second argument in the overloaded << operator function
			cout << "Service Time needed: " << pData_created->get_servcieTime() << endl;
			cout << "Total TIme needed for this customer: " << pData_created->get_totalTime() << endl;
			cout << "Arrival Time for this customer: " << normal_customer_arrival_time << endl << endl << endl;


			//cout << "" << pData_created->get_pHead_grocery();

			//if (normal_lane_queue.get_pTail() == pMem) //means we have only one customer on the the normal lane
			//{
			//	first_customer_service_time_normal_lane = pData_created->get_servcieTime() + 1;
			//}

			arrival_time_normal_lane = rand() % 6 + 3; // 3 4 5 6 7 8
			normal_customer_arrival_time = arrival_time_normal_lane;
		}



		////////////////////////////enqueuing a new customer in the express lane////////////////////////////////////
		if (arrival_time_express_lane == 0)
		{
			cout << "A new customer arrived on a express lane. Mins elapsed: " << min_elapsed  << endl;

			Data* pData_created = new Data(express_lane);
			GroceryList* pGroceryList_created = new GroceryList(express_lane);
			pData_created->set_pHead_grocery_list(pGroceryList_created);
			QueueNode* pMem = new QueueNode;
			express_lane_queue.enqueue(express_lane, express_lane_queue, pData_created, pMem); //populate a customer standing on an express lane
			

			pData_created->set_serviceTime(pData_created->get_pHead_grocery_list()->get_how_many_groceries());
			pData_created->set_totalTime(express_lane_queue.calculate_total_time());
			
			if (express_lane_queue.get_pHead() == express_lane_queue.get_pTail())
			{
				first_customer_service_time_express_lane = pData_created->get_servcieTime();
			}

			//let's print out basic info about this new customer!!
			cout << "Customer Number: " << pData_created->get_customerNumber() << endl;
			cout << "The number of groceries this customer has: " << pData_created->get_pHead_grocery_list()->get_how_many_groceries() << endl;
			//this works too //cout << "This customer's grocery List: "; pData_created->get_pHead_grocery_list()->print_each_grocery();// << endl;
			//this would crash because we are cout << void type into an argument!!! 
			//cout << "This customer's grocery List: " << pData_created->get_pHead_grocery_list()->print_each_grocery();// << endl;
			cout << "This customer's grocery List: " << *pData_created->get_pHead_grocery_list() << endl; //the arrow exectuted before star
			//cout << "This customer's grocery List: " << pData_created->get_pHead_grocery_list() << endl; //would print the address
			cout << "Service Time needed: " << pData_created->get_servcieTime() << endl;
			cout << "Total TIme needed for this customer: " << pData_created->get_totalTime() << endl;
			cout << "Arrival Time for this customer: " << express_customer_arrival_time << endl << endl << endl;

			//cout << "" << endl;  there are two fucntion << invoked which are chained together in a single line of code
			//the return value from the func cout << "" will also be used as a ____ << endl;

			//cout << "" << pData_created->get_pHead_grocery();

			//if (express_lane_queue.get_pTail() == pMem) //means we have only one customer on the the normal lane
			//{
			//	first_customer_service_time_express_lane = pData_created->get_servcieTime();
			//}

			arrival_time_express_lane = rand() % 5 + 1; // 1 2 3 4 5 //make sure the time is is not swapped with the normal lane!!!!!!!!!!!!!!!
			express_customer_arrival_time = arrival_time_express_lane;
		}
		
		
		//////////////////////////////////////////dequeue a customer on the normal lane///////////////////////////////
		if (!normal_lane_queue.isEmpty() && first_customer_service_time_normal_lane == 0)
		{
	
			cout << "A normal lane customer  " << normal_lane_queue.get_pHead()->get_pData()->get_customerNumber() << "  just finished checking out! Mins elapsed: " << min_elapsed << endl;
			cout << "Total Time it took for the customer  " << normal_lane_queue.get_pHead()->get_pData()->get_customerNumber() << "   to get the request done including the waiting time: "
				<< normal_lane_queue.get_pHead()->get_pData()->get_totalTime() << " mins " << endl << endl;

			
			normal_lane_queue.dequeue();
			
			
			//after dequeueing
			if (normal_lane_queue.isEmpty())
			{
				first_customer_service_time_normal_lane = 0;
			}

			else
			{
				//update the next customer's service time!!!
				//normal_lane_queue.set_pHead(normal_lane_queue.get_pHead()->get_pNext());
				first_customer_service_time_normal_lane = normal_lane_queue.get_pHead()->get_pData()->get_servcieTime();
			}
			
		}

		

		////////////////////////////////////////dequeue a customer on the express lane////////////////////////////////////////
		if (!express_lane_queue.isEmpty() && first_customer_service_time_express_lane == 0)
		{
			
			cout << "An express lane customer  " << express_lane_queue.get_pHead()->get_pData()->get_customerNumber() << "  just finished checking out! Mins elapsed: " << min_elapsed  << endl;
			cout << "Total Time it took for the customer  " << express_lane_queue.get_pHead()->get_pData()->get_customerNumber() << "   to get the request done including the waiting time: " 
				<< express_lane_queue.get_pHead()->get_pData()->get_totalTime() << " mins " << endl << endl;

			express_lane_queue.dequeue();

			if (express_lane_queue.isEmpty())
			{
				first_customer_service_time_express_lane = 0;
			}

			else
			{
				//update the next customer's service time!!!
				//express_lane_queue.set_pHead(express_lane_queue.get_pHead()->get_pNext());
				first_customer_service_time_express_lane = express_lane_queue.get_pHead()->get_pData()->get_servcieTime();
			}
			
		}


		////////////////////////////////////////////// //print the entire queue for each lane!!//////////////////////////////////
		if (print_entire_queue_every_ten_mins == 0)
		{
			cout << "Time Elapsed: " << min_elapsed << "   Let's print out each queue!" << endl << endl;

			cout << "A Normal lane Cash Register <--:  ";
			normal_lane_queue.printQueue();

			cout << endl << endl;

			cout << "An Express Lane Cash Register <--:  ";
			express_lane_queue.printQueue();

			print_entire_queue_every_ten_mins = 10; //reset the value!!!!
		}

		arrival_time_normal_lane--;
		arrival_time_express_lane--;

		if (first_customer_service_time_normal_lane > 0) first_customer_service_time_normal_lane--;
		
		if (first_customer_service_time_express_lane > 0) first_customer_service_time_express_lane--;
		
		
		print_entire_queue_every_ten_mins--;

		if (min_elapsed == 13399) success = true;
	}


	cout << "\n\n\n24 Hours elapsed! Customer Number will be resat to 1 again, if you run this simulation again!" << endl;

	return success;
}


