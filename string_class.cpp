#include "string_class.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//*************************************************************************************
//Name:	Class string_class default constructor
//Precondition: Class string_class is not initialized
//Postcondition: Class string_class is initialized
//Description:  initializes class string_class
//
//*************************************************************************************

string_class::string_class()
{
	current_string = "";
}

//*************************************************************************************
//Name:	Class string_class explicit constructor
//Precondition: Class string_class has no objects attached to it
//Postcondition: Class string_class has an object attached to it
//Description:  initializes Class string_class objects
//
//*************************************************************************************

string_class::string_class(string string_in)
{
	current_string = string_in;
}

//*************************************************************************************
//Name:	Class string_class bool member function
//Precondition: Current_string variable of a class string_class object has not been evaluated
//Postcondition: Current_string variable of a class string_class object has not been evaluated
//Description:  returns true if current_string is a palindrome false if not
//
//*************************************************************************************

bool string_class::palindrome()
{
	string backwards, forwards, backwards_upper, forwards_upper;

	// loop removes space 
	for (int i = current_string.length() - 1; i >= 0; i--) // from right to left
	{
		backwards += current_string[i];
	}
	// from left to right
	forwards = current_string;

	// modified values
	backwards_upper = backwards;
	forwards_upper = forwards;

	// values to all caps
	for (int i = 0; i < backwards_upper.length(); i++)
	{
		backwards_upper[i] = toupper(backwards_upper[i]);
	}
	for (int i = 0; i < forwards_upper.length(); i++)
	{
		forwards_upper[i] = toupper(forwards_upper[i]);
	}

	// checks for palindrome
	if (backwards_upper == forwards_upper)
	{
		return true;
	}
	return false;
}
//*************************************************************************************
//Name:	Class string_class void member funtion replace_all
//Precondition: Current_string state is unchanged
//Postcondition: Current_string state is modified
//Description:  Searches for old_string in current_string and replaces those parts with new_string 
//	
//*************************************************************************************
void string_class::replace_all(string old_string, string new_string)
{
	string temp_string, backup, string_result;
	int old_size = old_string.length();
	bool evaluation = false;

	// case selection
	backup += current_string;

	if (old_string.length() > current_string.length())
	{
		bool evaluation = false;
	}
	else
	{
		// current string change
		for (int i = 0; i < current_string.length(); i++)
		{
			temp_string = current_string[i];

			for (int j = 1; j < old_size; j++)
			{

				// lap 2
				if (!(i + j > current_string.length()))
				{
					temp_string += current_string[i + j];
				}

				if (temp_string == old_string)
				{
					evaluation = true;

					for (int k = 0; k < old_size; k++)
					{
						current_string.erase(current_string.begin() + i);
					}
					current_string.insert(i, new_string);
					i += old_size;
					string_result = current_string;
				}

			}

			if (new_string.empty())
			{
				if (old_size <= 1)
				{
					if (current_string.at(i) != old_string[0]) { string_result += current_string.at(i); evaluation = true; }
				}
			}
		}
	}
	current_string = string_result;
	if (evaluation == false) { current_string = backup; }
}
//*************************************************************************************
//Name:	Class string_class friend ostream& operator<<
//Precondition: no input arguments
//Postcondition: explicit constructor is overloaded displaying multiple objects through << operator 
//Description:  overloading operator that displays current_string objects with chaining
//
//*************************************************************************************

ostream& operator<<(ostream& out, string_class& string_class_obj)
{
	out << string_class_obj.current_string;
	return out;
}