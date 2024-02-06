#include "Queue.h"

/********************************************************************************************************************
* Function: get_pHead()
* Description: a getter function for pHead which is one of private members from Queue class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: pHead
*********************************************************************************************************************/
QueueNode* Queue::get_pHead()
{
	return pHead;
}


/********************************************************************************************************************
* Function: set_pHead()
* Description: a setter function to update a pHead (a pointer), a private member from Queue class with a new pointer value.
* Input parameters: new_pHead: an updated pHead pointer passed in.
* Returns: Nothing
*********************************************************************************************************************/
void Queue::set_pHead(QueueNode* new_pHead)
{
	pHead = new_pHead;
}



/********************************************************************************************************************
* Function: get_pTail()
* Description: a getter function for pTail which is one of private members from Queue class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: pTail
*********************************************************************************************************************/
QueueNode* Queue::get_pTail()
{
	return pTail;
}


/********************************************************************************************************************
* Function: set_pTail()
* Description: a setter function to update a pHead (a pointer), a private member from Queue class with a new pointer value.
* Input parameters: new_pTail: an updated new_pTail pointer passed in.
* Returns: Nothing
*********************************************************************************************************************/
void Queue::set_pTail(QueueNode* new_pTail)
{
	pTail = new_pTail;
}



/********************************************************************************************************************
* Function: isEmpty()
* Description: Checks for whether or not pHead pointer to a queue is empty.
* Input parameters: Nothing
* Returns: a boolean value
*********************************************************************************************************************/
bool Queue::isEmpty() //check if the queue is empty
{
	if (pHead == nullptr) return true; //the queue is empty

	return false; //the queue is not empty!
}



/********************************************************************************************************************
* Function: printQueue()
* Description: Prints each customer number standing on a lane.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Queue::printQueue() //not the way with interacting not suposed to maniuplate sth that is outside of tail and head
{
	QueueNode* traverse_ptr = pHead;

	int print_customer_number = 0;
	int print_service_time = 0;
	int print_total_time = 0;

	if (!isEmpty())
	{
		while (traverse_ptr != nullptr)
		{                //get ptr to Data!!

			print_customer_number = traverse_ptr->get_pData()->get_customerNumber();
			print_service_time = traverse_ptr->get_pData()->get_servcieTime();
			print_total_time = traverse_ptr->get_pData()->get_totalTime();

			/*cout << "Customer Number: \n" << print_customer_number << endl;
			cout << "Service Time: \n" << print_service_time << endl;
			cout << "Total Time: \n" << print_total_time << endl << endl;*/

			cout << "Customer " << print_customer_number << "  <----  ";

			//updating the pointer
			traverse_ptr = traverse_ptr->get_pNext(); //update the pointer which is a private member of a different class
		}

		cout << endl << endl;

	}

	else
	{
		cout << "There is no customer waiting on lane currently! Highly recommend standing on this lane!\n" << endl;
	}
	
}



/********************************************************************************************************************
* Function: enqueue()
* Description: Enqueues a new customer to the last node standing on a lane (First in First out Queue data structure).
* Input parameters: lane: distinguishes from a normaln lane and an express lane, customer_lane: an object that belongs to Queue class
*                   pData_created: Data class object passed by an referance, pMem: QueueNode class object passed by referance.
* Returns: a boolean value
*********************************************************************************************************************/
bool Queue::enqueue(int lane, Queue customer_lane, Data* pData_created, QueueNode* pMem)
{
	bool success = false;

	//Data* pData_created = new Data(lane, customer_lane);
	//QueueNode* pMem = new QueueNode;
	
	//pMem->get_pData()->set_customerNumber(pData_created->get_customerNumber()); //pMem->pData->customer
	
	//customer_lane.get_pTail()->set_pNext(pMem);
	pMem->set_pData(pData_created);
	//dont need to set pNext = nullptr because of a constructor.
	

	if (pMem != nullptr) //successfully made a node
	{
		if (isEmpty()) //empty
		{
			this->pHead = pMem; //inserting the first node into an empty linked list!!!
			//this->pTail = pMem;
		}

		else //if adding a subsequent node to the queue.
		{
			//ptail is a poninter to the Quenode!!
			this->pTail->set_pNext(pMem);
			//this->pTail = this->pTail->get_pNext();
		}

		//updating the pTail ptr!!
		this->pTail = pMem;

		success = true;
	}

	return success;
}


/********************************************************************************************************************
* Function: dequeue()
* Description: Dequeues a first customer standing on a lane (First in First out Queue data structure).
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
bool Queue::dequeue() //dequeing the front of the list!!!!
{
	bool success = false;

	if (!isEmpty())  //if the queue is not empty
	{
		//in queue we do not need to traverse through this linked list!!!!!!!!!!!!!!!!!!!!!!!
		QueueNode* pTemp = this->pHead; //temp pointer which is a local varaiable!

		if (this->pHead == this->pTail) //means among non-empty queues, if the remaining node is the last one.
		{
			this->pHead = nullptr;
			this->pTail = nullptr;
		}

		else if(this->pHead != this->pTail)
		{
			this->pHead = this->pHead->get_pNext(); //updating the head ptr before deletion of the node to prevent a dangling pointer
		}

		delete pTemp; //delete (dequeue the node) standning at the first line( time for u to go gets groceries).

		success = true;
	}

	//if the queue is empty with both pHead and pTail == nullptr
	else cout << "The queue is empty! There is no one stadning on lane!\n" << endl;

	return success;
}



/********************************************************************************************************************
* Function: calculate_total_time()
* Description: calculates a total time needed for each customer stadning in a queue lane.
* Input parameters: Nothing
* Returns: total_time
*********************************************************************************************************************/
//this refers current instance of a class
int Queue::calculate_total_time()
{
	int total_time = 0;    //is an instance public function a dot operator needs to be proceded!!
	QueueNode* traverse_ptr = this->get_pHead();

	while (traverse_ptr != nullptr)
	{
		total_time = total_time + traverse_ptr->get_pData()->get_servcieTime();
		traverse_ptr = traverse_ptr->get_pNext(); //updating the pointer!!
	}

	return total_time;
}