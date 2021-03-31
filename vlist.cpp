#include <iostream>
#include <vector>
#include <string>
#include "vlist.h" using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: Constructor has not been invoked.
//Postcondition: count = 0; vector size is 9.
//Description: Constructs an instance of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////

vlist::vlist()
{
	cout << "Default Constructor Invoked" << endl;
	DB.reserve(9);// allocates initial capacity of vector
	count = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
////Function Name: vlist
////Precondition: A vlist object is being passed by reference.
////Postcondition: A hard copy of a vlist object has been created.
////Description: Creates a hard copy of a vlist object.
/////////////////////////////////////////////////////////////////////////////////////////////////

vlist::vlist(const vlist & Org)
{
	cout << "Copy Constructor Invoked" << endl;
	DB = Org.DB;// produces deep copy of object
}

/////////////////////////////////////////////////////////////////////////////////////////////////
////Function Name: ~vlist
////Precondition: Destructor has not been invoked.
////Postcondition: array DB deleted.
////Description: Deallocates memory of a vlist object.
/////////////////////////////////////////////////////////////////////////////////////////////////

vlist::~vlist()
{
	cout << "Destructor Invoked" << endl;
	DB.clear(); //reduces size of object vector to 0
	DB = {};
	count = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: isEmpty
//Precondition: vlist object needs to be checked for existing values
//Postcondition: vlist object has been checked for existing values
//Description: returns true if the vlist has no values false otherwise 
///////////////////////////////////////////////////////////////////////////////////////////////

bool vlist::isEmpty()
{	
	//checks for values in object vector
	if (DB.empty())
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: search
//Precondition: vlist object needs to be searched for a specific string
//Postcondition: iterator of string or end of vector is returned
//Description: searches object for a string and returns appropriate iterator or end of vector
///////////////////////////////////////////////////////////////////////////////////////////////

vector<string>::iterator vlist::search(const string& key)
{
	int j = 0;
	vector<string>::iterator i;

	// iterates through object vector
	for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++)
	{
		if (DB.at(j) == key)
		{
			cout << "Item Found" << endl;
			return i;// returns iterator of object vector with matching string
		}
		j++;
	}

	cout << "Item Not Found" << endl;
	i = DB.end();// sets iterator i to end of vector
	return i;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: insert
//Precondition: string needs to be inserted into object vector sorted
//Postcondition: string has been inserted into object vector sorted
//Description: input argument string is inserted into object vector sorted
///////////////////////////////////////////////////////////////////////////////////////////////

void vlist::insert(const string & key)
{
	if (DB.empty())// pushes string to empty vector
	{
		DB.insert(DB.begin(), key);
		//DB.push_back(key);
		count++;
	}

	else if (key >= DB.at(count - 1))// sorts string to back of vector sorted appropriately
	{
		DB.push_back(key);
		count++;
	}

	else// iterates through object vector and inserts string sorted appropriately
	{
		int j = 0;
		for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++)
		{
			if (key <= DB.at(j))// inserts string when smaller then current iterator
			{
				DB.insert(i, key);
				count++;
				return;
			}
			j++;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: remove
//Precondition: string needs to be removed from object vector
//Postcondition: string has been removed from object vector
//Description: calls search function to find iterator and removes iterator from object vector
//	if it exists or displays it wasn't found in the vector
///////////////////////////////////////////////////////////////////////////////////////////////

void vlist::remove(const string& key) 
{
	vector<string>:: iterator i = search(key);// locates iterator of string to remove if it exists

	if (i == DB.end())// string was not found display string does not exist
	{
		cout << "The string was not in the vector" << endl;
	}

	else
		DB.erase(i);// string was found and is erased
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print
//Precondition: object vector needs to be displayed
//Postcondition: object vector has been displayed
//Description: iterates through object vector and displays its elements
///////////////////////////////////////////////////////////////////////////////////////////////

void vlist::print() 
{	
	// iterates through object vector and displays its sorted elements
	for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++)
	{
		cout << *i << endl;
	}
	return;
}

