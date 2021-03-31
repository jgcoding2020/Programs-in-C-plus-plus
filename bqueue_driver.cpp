#include<iostream>
#include "bqueue.h"

using namespace std;

//********************************************************************************************
//Name:	Joshua Gardner		Z#:	Z15117842
//Course: Date Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
//Due Date:	3/10/2021	Due Time:	11:59pm
//Total Points: 25 Assignment module 8: queue program
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