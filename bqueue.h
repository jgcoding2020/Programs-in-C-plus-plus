#pragma once
#include <iostream>

using namespace std;

class bqnode 
{
public:
	int priority;
	bqnode* prev,* next;
};

class bqueue 
{
public:
	bqueue();
	~bqueue();
	bqueue(const bqueue& org);
	void enqueue(int A);
	void dequeue();
	void print();
private:
	bqnode* front;//useONLYone pointer
};
