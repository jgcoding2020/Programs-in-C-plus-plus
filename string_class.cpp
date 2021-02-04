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
	string pali_test;
	int capacity;
	int j = 0;
	int count = 0;

	capacity = current_string.length();

	for (int i = capacity - 1; i >= 0; i--)
	{
		pali_test[i] = current_string[j];
		if (toupper(pali_test[i]) == toupper(current_string[i]))
			count++;
		j++;
	}

	if (count == capacity - 1)
	{
		return true;
	}

	else
	{
		return false;
	}
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
	string temp_string;

	for (int i = 0; i < current_string.length();)
	{
		for (int j = 0; j < old_string.length();)
		{
			if (match(current_string, old_string, i))
			{
				temp_string = temp_string + new_string;
				i = i + old_string.length();
				j = j + old_string.length();
			}

			else
			{
				temp_string = temp_string + current_string[0];
				j = old_string.length();
				i++;
			}
		}
	}

	current_string = temp_string;

		cout << current_string;
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

//*************************************************************************************
//Name:	Class string_class bool member funtion match
//Precondition: replace_all function needs a bool result
//Postcondition: replace_all function receives a bool result
//Description:  Finds matching letters in sequence from index [0] to length of old_string 
//		returns true or false depending on whether a match is found each loop
//*************************************************************************************

bool string_class::match(string& current_string, string& old_string, int& i)
{
	int w = i;
	if (current_string.length() >= old_string.length())
	{
		for (int j = 0; j < old_string.length(); j++, w++)
		{
			if (current_string[w] != old_string[j])
			{
				return false;
			}
		}

		return true;
	}
	return false;
}
