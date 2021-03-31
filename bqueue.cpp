#include <iostream>
#include "bqueue.h"

using namespace std;

/***********************************************************************************/
//Name: default constauctor
//Precondition: class has not been initialized
//Postcondition: class has been initialized
//Decription: initializes class and sets its value to null
/***********************************************************************************/

bqueue::bqueue()
{
	front = 0;//sets front to null
}

/***********************************************************************************/
//Name: destructor
//Precondition: There are no out of scope memory locations
//Postcondition: Out of scope queue memory locations are deleted
//Decription: Deletes queue memory locations created that become out of scope
/***********************************************************************************/

bqueue::~bqueue()
{
	dequeue();//calls to dequeue which removes the front node from the list
}

/***********************************************************************************/
//Name: copy constructor
//Precondition: no copies of objects have been created
//Postcondition: copies of objects have been created
//Decription: creates a copy of objects when called for
/***********************************************************************************/

bqueue::bqueue(const bqueue& org)
{
	front = 0;
	bqnode* p = org.front; //creates bqnode that points to front of object queue being copied

	do {//loops through original queue and calls to enqueue function to copy node priority data
		enqueue(p->priority);
		p = p->next;
	} while (p != org.front);// Once p is back to front loop terminates

}

/***********************************************************************************/
//Name: enqueue
//Precondition: there is a new node needing to be added to the queue list
//Postcondition: a new node has been added to the queue list
//Decription: allocates memory for a new node which is added to the back of the queue
//	and the queue is relinked appropriately
/***********************************************************************************/

void bqueue::enqueue(int A)
{
	bqnode* p = new bqnode;//allocated memory for new queue node

	if (front == 0)//if no queue exists the first node is established
	{//addresses for next and previous get shifted appropriately to maintain connectivity
		p->priority = A;
		p->next = p;
		p->prev = p;
		front = p;
	}

	else//if a queue already exists an additional node is added to the back of the queue
	{//addresses for next and previous are being shifted appropriately to maintain connectivity
		p->priority = A;
		p->next = front;
		p->prev = front->prev;
		front->prev->next = p;
		front->prev = p;
	}
}

/***********************************************************************************/
//Name: dequeue
//Precondition: a node is needing to be removed from the queue list
//Postcondition: a node has been removed from the queue list
//Decription: a node is removed from the front of the queue list and the list is 
//	relinked appropriately
/***********************************************************************************/

void bqueue::dequeue()
{
	bqnode* p;//creates node pointer

	if (front == 0)//the list is empty nothing to dequeue front remains null
	{
		front = 0;
	}
	
	else if (front == front->next)//if there is only one node front is set to null and p is deleted
	{
		p = front;
		front = 0;
		delete p;
	}
	
	else//if there is more then 1 item in the list the front is deleted
	{//addresses of next and previous are appropriately shifted to maintain list connectivity
		p = front;
		front = front->next;
		p->prev->next = front;
		front = p;
		p = p->prev;
		front->next->prev = p;
		p = front;
		front = front->next;
		delete p;
	}
}

/***********************************************************************************/
//Name: print
//Precondition: the queue list needs to be displayed
//Postcondition: the queue list has been displayed
//Decription: traverses through the queue list from front to back and displays the  
//	priorities within each node in the queue list
/***********************************************************************************/

void bqueue::print()
{
	bqnode* p;//created node pointer
	p = front;//sets pointer to front of the queue list

	{
		do {//if there is a queue list the priorities are displayed from front to back
			if (p != 0)
			{
				cout << p->priority << endl;
				p = p->next;
			}
			else//there are no priorities to display so p is set to front and null
				p = front;
		} while (p != front);//lopp continues until p == front
	}
}
