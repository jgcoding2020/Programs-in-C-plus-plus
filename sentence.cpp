#include <iostream>
#include <string>
#include "sentence.h"

//*************************************************************************************
//Name:	Class sentence default constructor
//Precondition: Class sentence is not initialized
//Postcondition: Class sentence_class is initialized
//Description:  initializes class sentence_class
//
//*************************************************************************************

sentence::sentence()
{
	front = back = 0;
}

//*************************************************************************************
//Name:	length 
//Precondition: The character length of the string is unknown 
//Postcondition: The character length of the string is evaluated and stored
//Description: A pointer to this object traverses through a while loop and consecutively 
//				adds together the totals of the list node character lengths
//
//*************************************************************************************

int sentence::length()
{
	int string_length = 0;
	word* picked = this->front;// temp pointer assigned address of front 

	if (picked == 0)//if the pointer address is null
	{
		return string_length;//returns null
	}
	else
	{
		while (picked != 0)//pointer does not equal null
		{
			string_length += picked->term.length();//adds length of node strings together
			picked = picked->next;//traverses nodes
		}
		return string_length;//returns string length
	}
}

//*************************************************************************************
//Name:	operator<< 
//Precondition: Objects can not directly be displayed through the insertion operator
//Postcondition: Objects can now be directly displayed through the insertion operator
//Description: A temporary pointer traverses through the adresses of the nodes within the 
//				linked list and displays the term (word) stored in each list node.
//
//*************************************************************************************

ostream& operator<<(ostream& out, const sentence& A)
{
	word* temp;//temp pointer declaration
	
	for (temp = A.front; temp != 0; temp = temp->next)//loop traverses through nodes
	{
		out << temp->term;//dispalys each term in the linked list
	}
	return out;
}

//*************************************************************************************
//Name:	explicit constructor
//Precondition: The objects values have not been initialized to anything other then null
//Postcondition: The objects have been initialized with the appropriate values
//Description: The object has been initialized and the string has been parced so that each
//				word and/ or space has been saved to node (address) within the linked list
//
//*************************************************************************************

sentence::sentence(const string& s)
{
	front = 0;
	back = 0;
	int length = s.length();//checks input argument string length

	if (length == 0)//if string length is 0
	{
		front = 0;//front equals 0
		return;//exit function
	}

	string temp, space;//temp strings for words and spaces
	space = " ";
	for (int i = 0; i < length; i++)//loops through length of string
	{
		if (s[i] != ' ')//checks for nonspace characters in string
		{
			temp += s[i];//adds non space characters to temp string
		}

		if (s[i] == ' ')//checks for space
		{
			add_back(temp);//adds the temp string to the list
			add_back(space);//adds the space to the list
			temp = "";//clears the temp string
		}

		if (s[i + 1] == '\0')//checks for null
		{
			add_back(temp);//adds temp string to back of list
		}
	}
}

//*************************************************************************************
//Name:	copy constructor
//Precondition: The input argument has not been copied
//Postcondition: A deep copy of the object argument is produced
//Description: An object pointer is assigned the address of the input argument pointer 
//				object address. The pointer traverses through the nodes and adds each
//				node to the back of the list.
//*************************************************************************************

sentence::sentence(const sentence& org)
{
	front = 0;
	back = 0;

	word* node = org.front;//creates pointer to input argument object

	while (node != 0)//traverses through list until node equals null
	{
		add_back(node->term);//adds term to the back of the list
		node = node->next;//traverses node to next list node
	}
}

//*************************************************************************************
//Name:	isequal
//Precondition: Object equality has not been determined 
//Postcondition: Object equality has been determined
//Description: Two objects are cheacked for equality and returns true or false
//
//*************************************************************************************

bool sentence::isEqual(sentence& B)
{
	if (length() != B.length())//automatic length fail test
	{
		return false;
	}

	word* ptrA = new word;//allocates new memory for pointers
	word* ptrB = new word;

	ptrA = front;//sets pointers equal to current fron and input argument front
	ptrB = B.front;

	while (ptrA != 0 && ptrB != 0)//loop condition that both lists don't eqaul null
	{
		
		if (ptrA->term != ptrB->term)//returns false if both terms are not equal
		{
			return false;
		}

		ptrA = ptrA->next;//traverses both list nodes
		ptrB = ptrB->next;
	}

	
	return true;//returns true if passed fail tests 
}

//*************************************************************************************
//Name:	operator=
//Precondition: String has not been added to the object linked list
//Postcondition: String has been added to the object linked list
//Description: Allows an object to have a string attached to it in a singly linked list 
//				through the overloaded operator=
//*************************************************************************************

void sentence::operator=(const string& s)
{
	front = 0;//refer to explicit constructor
	back = 0;
	int length = s.length();

	if (length == 0)
	{
		front = 0;
		return;
	}

	string temp, space;
	space = " ";
	for (int i = 0; i < length; i++)
	{
		if (s[i] != ' ')
		{
			temp += s[i];
		}

		if (s[i] == ' ')
		{
			add_back(temp);
			add_back(space);
			temp = "";
		}

		if (s[i + 1] == '\0')
		{
			add_back(temp);
		}
	}
}

//*************************************************************************************
//Name:	destructor
//Precondition: Uneeded data in memory has not been destroyed
//Postcondition: Uneeded data in memory has been destroyed
//Description: A pointer traverses through the linked list of uneeded data and deletes 
//				each node in the linked list.
//*************************************************************************************

sentence::~sentence()
{
	cout << "Destructor has been called\n";// destroys objects not needed
	word* remove_node = front;

	while (remove_node != 0) {
		word* next = remove_node->next;
		delete remove_node;
		remove_node = next;
	}
	front = 0;
}

//*************************************************************************************
//Name:	add_back
//Precondition: The string has not been added to the specified linked list
//Postcondition: The string has been added to the specified linked list
//Description: The string is added to the back of the linked list
//
//*************************************************************************************

void sentence::add_back(string& s)
{
	if (front == 0)//adds string to front of the list
	{
		front = new word;
		front->term = s;
		front->next = 0;
		back = front;
	}

	else
	{
		word* p = new word;//adds string to back of the list
		p->next = 0;
		p->term = s;
		back->next = p;
		back = p;
	}
}

//*************************************************************************************
//Name:	operator+
//Precondition: The objects linked lists have not been added together
//Postcondition: The objects linked lists have been added together
//Description: The input argument object linked list is added to the back of the 
//				current object linked list.
//*************************************************************************************

void sentence::operator+(sentence& B)
{
	word* addList = B.front;

	if (addList != 0)//adds input argument object to current object
	{
		while (addList != 0)
		{
			add_back(addList->term);
			addList = addList->next;
		}
	}

	else
	{
		return;
	}
}

//*************************************************************************************
//Name:	search
//Precondition: The string has not been identified in the linked list 
//Postcondition: The string has been identified in the linked list
//Description: A pointer traverses through the linked list until it finds a matching
//				string value. The address of the matched value is returned.
//*************************************************************************************

word* sentence::search(const string& s)
{
	word* node_remove = front;
						
	while (node_remove != 0)
	{
		if (node_remove->term == s)
		{
			return node_remove;//returns node to remove when it's equal to the input string
		}
		node_remove = node_remove->next;
	}
	return node_remove;
}

//*************************************************************************************
//Name:	remove
//Precondition: The input argument string has not been removed from the list 
//Postcondition: The input argument string has been removed from the list
//Description: Removes the address found in the search function from the linked list
//				withoughout disrupting the connectivity of the linked list
//*************************************************************************************

void sentence::remove(const string& s)
{
	word* node_remove = search(s);//provides the address of node to be removed						
	if (node_remove == 0)//if search result is null end function							
	{
		return;
	}
	else								
	{									
		if (node_remove == front && front == back)//if front and backpoint to the same node
		{
			delete node_remove;//delete single node list
			front = back = 0;//set pointers to null
		}								
		else if (node_remove == front)//if the list is longer then 1 node and we remove the front node
		{
			front = front->next;//set front equal to the next node address
			delete node_remove;//delete the original front node
		}								
		else
		{
			word* back_ptr = front;		
			while (back_ptr != 0 && back_ptr->next != node_remove)//ptr != null and the next node is not to be deleted
			{
				back_ptr = back_ptr->next;//traverse ptr
			}

			if (node_remove == back)//when node to be deleted is the last node
			{
				back = back_ptr;//sets back to ptr
			}

			back_ptr->next = node_remove->next;//changes next address value to address of node beyond delete node
			delete node_remove;//delete node
		}
	}
}

//*************************************************************************************
//Name:	operator=
//Precondition: Object has not been assigned the value of the input argument object
//Postcondition: Object has been assigned the value of the input argument object
//Description: Overloads the operator= to allow assignemnt of one object to another.
//
//*************************************************************************************

sentence& sentence::operator=(const sentence& w)
{
	front = 0;//sets one object = to another
	back = 0;

	word* ptrA = w.front;

	while (ptrA != 0)
	{
		add_back(ptrA->term);
		ptrA = ptrA->next;
	}
	
	return *this;
}