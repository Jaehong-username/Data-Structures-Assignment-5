#include "GroceryNode.h"

#include "GroceryList.h"


/********************************************************************************************************************
* Function: GroceryNode()
* Description: a constructor from GroceryNode class: initializes private members of GroceryNode class.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
GroceryNode::GroceryNode()
{

	int i = rand() % 8;
	grocery_item = grocery_items_list[i];
	pNext = nullptr;
}


/********************************************************************************************************************
* Function: ~GroceryNode()
* Description: a destructor: deallocates an object, implictly invoked when the object goes out of scope.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
GroceryNode::~GroceryNode() //destructor!
{
	//delete pNext; //make sure to comment it out, otherwise it will be deleting not only a single node but also the rest of the nodes
	//in the list since, it is a ptr to the next node that gets deallocated.
}



/********************************************************************************************************************
* Function: get_grocery_item()
* Description: a getter function for grocery_item which is one of private members from QueueNode class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: grocery_item
*********************************************************************************************************************/
string GroceryNode::get_grocery_item()
{
	return grocery_item;
}


/********************************************************************************************************************
* Function: get_pNext()
* Description: a getter function for pNext which is one of private members from GroceryNode class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: pNext
*********************************************************************************************************************/
GroceryNode* GroceryNode::get_pNext()
{
	return pNext;
}


/********************************************************************************************************************
* Function: set_pNext()
* Description: a setter function to update a pNext (a pointer), a private member from QueueNode class with a new pointer value.
* Input parameters: new_pNext: an updated new_pNext pointer passed in.
* Returns: Nothing
*********************************************************************************************************************/
void GroceryNode::set_pNext(GroceryNode* new_pNext)
{
	pNext = new_pNext;
}


