#pragma once

#include <iostream>
#include <string>

using namespace std;

typedef string stack_element;

class stack_node
{
public:
	stack_element data;
	stack_node* next;
};

class stack
{
public:
	stack() {/*cout<<"Inside Default Constructor\n"*/; s_top = 0; }
	~stack(); // destructor
	stack(const stack&); // copy constructor
	stack_element top(); // returns top of stack data
	void pop(); // deletes top node from list
	void push(const stack_element&); // adds new node to top of list
	void print(); // displays linked list from top to bottom
	void build_stack(const string& C);

private:

	stack_node* s_top;
};