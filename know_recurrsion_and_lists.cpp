#include <iostream>

using namespace std;

//********************************************************************************************
//Name:	Joshua Gardner		Z#:	15117842
//Course: Date Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
//Due Date:	3/29/2021	Due Time:	11:59pm
//Total Points: 25 Assignment module 10B: fun recursion program
//Description: creates a linked list and uses a fun function to return the data recursively
//*********************************************************************************************

//node class
class node {
public:
	int data;//data slot
	node* next;//next node address
};

void fun(node* start);//recursive display function protoype
void add_back(class node*& front, class node*& back, int x);//node list building function prototype


int main()
{	
	node* front = 0;//front node pointer
	node* back = 0;//back node pointer

	for (int i = 1; i <= 6; i++)//loop calling to node building function inserting i values
	{
		add_back(front, back, i);//call to node building function
	}
	cout << "******************************************************************"
		<< "********************************************\n\n";
	cout << "The following numbers are being displayed by a recursive function" 
		<< " from a singly linked list in a \"fun\" way: \n\n";
	cout << "******************************************************************"
		<< "********************************************\n\n";
	fun(front);//call to recursive node list display function
	cout << endl;
	cout << "\n******************************************************************"
		<< "********************************************\n";
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: fun
//Precondition: node list needs to be displayed
//Postcondition: node list has been displayed
//Description: uses a direct recursive call on itself and displays the node list entertainingly
///////////////////////////////////////////////////////////////////////////////////////////////

void fun(node* start)//recursive node list display function
{
	if (start == 0)
		return;
	cout << start->data;
	if (start->next != 0)
		fun(start->next->next);
	cout << start->data;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: add_back
//Precondition: data needs to be added to the linked list
//Postcondition: data has been added to the linked list
//Description: takes an integer argument and inserts it to a new node at the back of the list
///////////////////////////////////////////////////////////////////////////////////////////////

void add_back(class node*& front, class node*& back, int x)//node list building function
{
	if (front == 0)// if no list exists build first node
	{
		front = back = new node;
		front->data = x;
		front->next = 0;
	}

	else//if node exists add new node to back
	{
		back->next = new node;
		back = back->next;
		back->data = x;
		back->next = 0;
	}
}
