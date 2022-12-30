#include<iostream>
#include "bqueue.h"

using namespace std;

//********************************************************************************************
//Name:	Joshua Gardner
//Date:	3/10/2021
//Content: queue program
//Description: Utilizes a circular doubly linked list to create a queue of integers
//*********************************************************************************************

int main()
{
	bqueue k;
	k.enqueue(60);
	k.print();
	k.enqueue(20);
	k.enqueue(30);
	k.print();
	k.enqueue(10);
	k.print();
	k.enqueue(50);
	k.enqueue(40);
	k.print();
	bqueue j = k;
	j.dequeue();
	j.print();
	j.dequeue();
	j.dequeue();
	j.dequeue();
	j.print();
	j.dequeue();
	j.dequeue();
	j.print();
	j.dequeue();
	j.dequeue();

	return 0;
}
