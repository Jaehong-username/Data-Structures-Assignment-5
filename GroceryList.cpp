#include "GroceryList.h"


/********************************************************************************************************************
* Function: GroceryList()
* Description: a constructor from GroceryList class: initializes private members of GroceryList class.
*              If it is a normal lane how_many values will range from 3 to 8, while if it's an express lane how_many_values
*              will range from 1 to 5.
* Input parameters: normal_or_express: distinguishes between a normal lane and an express lane.
* Returns: Nothing
*********************************************************************************************************************/
GroceryList::GroceryList(int normal_or_express)
{
	pHead_grocery = nullptr;

	if (normal_or_express == 0) //it is a normal lane so total number of items 3-8;
	{
		how_many = rand() % 6 + 3;

	}

	else //it is an express lane. so total number of items 1-5
	{
		how_many = rand() % 5 + 1;
	}

	insert_grocery_node(); //we need to actually call this func!!! otherwise nodes of each grocery item will not be inserted to the list!
}


/********************************************************************************************************************
* Function: ~GroceryList()
* Description: a destructor: deallocates an object, implictly invoked when the object goes out of scope.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
GroceryList::~GroceryList()
{
	/*GroceryNode ex;
	ex.test = 10;*/ //friend keyword test
	delete pHead_grocery;
}


/********************************************************************************************************************
* Function: get_how_many_groceries()
* Description: a getter function for how_many which is one of private members from GroceryList class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: how_many
*********************************************************************************************************************/
int GroceryList::get_how_many_groceries()
{
	return how_many;
}


/********************************************************************************************************************
* Function: get_pHead_grocery()
* Description: a getter function for pHead_grocery which is one of private members from GroceryList class to get access in
*              a different class.
* Input parameters: Nothing
* Returns: pHead_grocery
*********************************************************************************************************************/
GroceryNode* GroceryList::get_pHead_grocery()
{
	return pHead_grocery;
}


/********************************************************************************************************************
* Function: insert_grocery_node()
* Description: Inserts a grocery node to the linked list of grocery items.
* Input parameters: Nothing
* Returns: success
*********************************************************************************************************************/
bool GroceryList::insert_grocery_node()
{
	bool success = false;

	GroceryNode* temp_ptr = pHead_grocery;

	for (int i = 0; i < how_many; i++)
	{
		if (pHead_grocery == nullptr) //if no grocery
		{                     //no () just allocates space for it but not actualy call the constructor
			GroceryNode* pMem = new GroceryNode(); //create an new grocery node that has one randomly stored item
			pHead_grocery = pMem;
			temp_ptr = pMem; ///updating the temp ptr too.
		}

		else //if the list not empty
		{
			GroceryNode* pMem = new GroceryNode(); //create an new grocery node that has one randomly stored item
			//temp_ptr->(temp_ptr->get_pNext()) = pMem; //Question??????????
			temp_ptr->set_pNext(pMem);
			temp_ptr = temp_ptr->get_pNext(); //updating the ptr
		}

	}

	success = true;

	return success;
}



/********************************************************************************************************************
* Function: print_each_grocery()
* Description: Prints each grocery in the linked list.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void GroceryList::print_each_grocery()
{
	GroceryNode* traverse_ptr = /*this->*/pHead_grocery;

	cout << traverse_ptr;
	while (traverse_ptr != nullptr)
	{
		cout << "  " << traverse_ptr->get_grocery_item() << ", "; //get_pHead_grocery()->get_grocery_item(); will only print
		traverse_ptr = traverse_ptr->get_pNext();                         //the first grocery item bc it is the traverse ptr that gets updated
	}                                                             //instead of the get_pHead_grocery()

	cout << endl;
}



/********************************************************************************************************************
* Function: operator<<()
* Description: Prints each grocery in the linked list.
* Input parameters: stream: output stream, grocery_list: grocery_list object passed by referance.
* Returns: stream
*********************************************************************************************************************/
//copy   means copy consturct and destructor invoked.  when passing by ref  so  constructor and destructor will be inovoked
//function overloading
                              //we dont usually pass cout as a param, bc its usually pre-defined
std::ostream& operator<<(std::ostream& stream, GroceryList& grocery_list) //GroceryList& needs to be passed by ref instead of copy obj
{                                             //since it passes in GroceryList class, is good to define this overloaded func in GroceryList class
	GroceryNode* traverse_ptr = grocery_list.get_pHead_grocery();

	while (traverse_ptr != nullptr)
	{
		//stream << grocery_list.get_pHead_grocery()->get_grocery_item();
		stream << traverse_ptr->get_grocery_item() << ",   ";
		traverse_ptr = traverse_ptr->get_pNext();
	}

	//cout << grocery_list.get_pHead_grocery()->get_grocery_item()
	//cout << grocery_list.print_each_grocery();

	return stream;
}



