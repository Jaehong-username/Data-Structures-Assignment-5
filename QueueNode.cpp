#include "QueueNode.h"

#include "Queue.h"


/********************************************************************************************************************
* Function: QueueNode()
* Description: a constructor from QueueNode class: initializes private members of QueueNode class.
* Input parameters: normal_or_express: distinguishes between a normal lane and an express lane.
* Returns: Nothing
*********************************************************************************************************************/
QueueNode::QueueNode()
{
	pData = nullptr;
	pNext = nullptr;
}


/********************************************************************************************************************
* Function: ~QueueNode()
* Description: a destructor: deallocates an object, implictly invoked when the object goes out of scope.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
QueueNode::~QueueNode() 
{
	delete pData;  //not influencing the other nodes
	//delete pNext;  //QUenode not responisible for the next node.   default destructor: does not delete the object itself, not doing anything with ptr.  normal datatype like int leaves it alo
}


/********************************************************************************************************************
* Function: get_pData()
* Description: a getter function for pData which is one of private members from QueueNode class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: pData
*********************************************************************************************************************/
Data* QueueNode::get_pData()
{
	return pData;
}


/********************************************************************************************************************
* Function: set_pData()
* Description: a setter function to update a pData (a pointer), a private member from QueueNode class with a new pointer value.
* Input parameters: new_pData: an updated pData pointer passed in.
* Returns: Nothing
*********************************************************************************************************************/
void QueueNode::set_pData(Data* const new_pData)
{
	pData = new_pData;
}


/********************************************************************************************************************
* Function: get_pNext()
* Description: a getter function for pNext which is one of private members from QueueNode class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: pNext
*********************************************************************************************************************/
QueueNode* QueueNode::get_pNext()
{
	return pNext;
}


/********************************************************************************************************************
* Function: set_pNext()
* Description: a setter function to update a pNext (a pointer), a private member from QueueNode class with a new pointer value.
* Input parameters: new_pNext: an updated pNext pointer passed in.
* Returns: Nothing
*********************************************************************************************************************/
void QueueNode::set_pNext(QueueNode* const new_pNext)
{
	pNext = new_pNext;
}

//make a new node for q queue.
//QueueNode* QueueNode::make_queue_node(int lane, Queue& customer_lane, Data customerNumber)
//{
//	QueueNode* pMem = new QueueNode; //pointer to data and pointer to data
//	pMem->pData = customerNumber.make_data_memory(lane, customer_lane);
//	pMem->pNext = nullptr;
//
//
//	return pMem;
//}




