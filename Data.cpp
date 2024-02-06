#include "Data.h"

#include "QueueNode.h"

#include "Queue.h"

#include "GroceryList.h"

#include "GroceryNode.h"


/********************************************************************************************************************
* Function: Data()
* Description: a constructor from Data class: initializes private members of Data class, when passing lane as argument.
* Input parameters: lane: distinguishes between a normal lane and an express lane.
* Returns: Nothing
*********************************************************************************************************************/
Data::Data(int lane) //coupling issue not reliant on each other but cohesive enough 
{
	static int customerNumber_so_far = 0;
	customerNumber_so_far = customerNumber_so_far + 1;
	customerNumber = customerNumber_so_far;

	//servtime to process each customer's request
	//if (lane == 0) serviceTime = rand() % 5 + 1;// normal lane 3 ~ 8 service time
	//else serviceTime = rand() % 6 + 3;// express lane 1 ~ 5 service time
	
	//service time!!!
	GroceryList customer_groceryList(lane); //will popuilate grocery list object
	serviceTime = customer_groceryList.get_how_many_groceries();


	totalTime = 0;//calculate_total_time(customer_lane); //total time elasped

	//pHead_grocery = customer_groceryList.get_pHead_grocery();

	pHead_grocery_list = nullptr;
}


/********************************************************************************************************************
* Function: ~Data()
* Description: a destructor: deallocates an object, implictly invoked when the object goes out of scope.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
Data::~Data() //destructor
{
	//delete pHead_grocery;
	delete pHead_grocery_list;
}

//make a memory!
//Data* Data::make_data_memory(int lane, Queue& customer_lane)
//{
//	Data* pMem_data = new Data(lane, customer_lane);
//
//	return pMem_data;
//}


/********************************************************************************************************************
* Function: get_customerNumber()
* Description: a getter function for customerNumber which is one of private members from Data class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: customerNumber
*********************************************************************************************************************/
int Data::get_customerNumber()
{
	return customerNumber;
}


/********************************************************************************************************************
* Function: set_customerNumber()
* Description: a setter function to update a customerNumber, a private member from Data class with a new value.
* Input parameters: new_customer_number: an updated customer number passed in.
* Returns: Nothing
*********************************************************************************************************************/
void Data::set_customerNumber(const int new_customer_number)
{
	customerNumber = new_customer_number;
}



/********************************************************************************************************************
* Function: get_serviceTime()
* Description: a getter function for serviceTime which is one of private members from Data class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: serviceTime
*********************************************************************************************************************/
int Data::get_servcieTime() //data itself deleted
{
	return serviceTime;
}



/********************************************************************************************************************
* Function: set_serviceTime()
* Description: a setter function to update a serviceTime, a private member from Data class with a new value.
* Input parameters: new_service_time: an updated service time passed in.
* Returns: Nothing
*********************************************************************************************************************/
void Data::set_serviceTime(const int new_service_time)
{
	serviceTime = new_service_time;
}

//if not passed by referance it makes a local copy, if no return info wont get saved. 

//if not &  it has an error?? why?????????????????????????????????
//int Data::calculate_total_time(Queue lane)
//{
//	int total_time = 0;                     //is an instance public function a dot operator needs to be proceded!!
//	QueueNode* traverse_ptr = lane.get_pHead();
//
//	
//
//	while (traverse_ptr != nullptr)
//	{
//		total_time = total_time + traverse_ptr->get_pData()->serviceTime;
//		traverse_ptr = traverse_ptr->get_pNext(); //updating the pointer!!
//	}
//
//	return total_time;
//}


/********************************************************************************************************************
* Function: get_totalTime()
* Description: a getter function for totalTime which is one of private members from Data class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: totalTime
*********************************************************************************************************************/
int Data::get_totalTime()
{
	return totalTime;
}


/********************************************************************************************************************
* Function: set_totalTime()
* Description: a setter function to update a totalTime, a private member from Data class with a new value.
* Input parameters: new_service_time: an updated new_total_time passed in.
* Returns: Nothing
*********************************************************************************************************************/
void Data::set_totalTime(const int new_total_time)
{
	totalTime = new_total_time;
}

//GroceryNode* Data::get_pHead_grocery()
//{
//	return pHead_grocery;
//}
//
//void Data::set_pHead_grocery(GroceryNode* new_pHead_grocery_created)
//{
//	pHead_grocery = new_pHead_grocery_created;
//}


/********************************************************************************************************************
* Function: get_pHead_grocery_list()
* Description: a getter function for pHead_grocery_list which is one of private members from Data class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: pHead_grocery_list
*********************************************************************************************************************/
GroceryList* Data::get_pHead_grocery_list()
{
	return pHead_grocery_list;
}


/********************************************************************************************************************
* Function: set_pHead_grocery_list()
* Description: a setter function to update a pHead_grocery_list, a private member from Data class with a new value.
* Input parameters: new_pHead_grocery_list_created: an updated new_pHead_grocery_list_created passed in.
* Returns: Nothing
*********************************************************************************************************************/
void Data::set_pHead_grocery_list(GroceryList* new_pHead_grocery_list_created)
{
	pHead_grocery_list = new_pHead_grocery_list_created;
}


