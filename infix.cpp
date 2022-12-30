#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

//********************************************************************************************
//Name:	Joshua Gardner
//Date:	3/5/2021
//Content: stack program
//Description: Utilizes a singly linked list to input a string as a post/prefixed operator and 
//		displays the infix results
//*********************************************************************************************

int main()
{
	stack S;

	string C;
	char reply;

	do {
		cout << "Please enter your post fixed operator:" << endl;
		getline(cin, C);

		stack list;
		list.build_print_stack(C);
		cout << endl << "If you would like to enter another press y:" << endl;
		cin >> reply;
		cin.ignore();
	} while (reply == 'y' || reply == 'Y');

	return 0;
}

