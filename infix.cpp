#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

string user_input_validity(string& C);
string remove_space(string equation);

int main()
{
	stack S;

	S.push("a");
	S.push("b");
	S.push("c");
	S.push("d");
	S.push("e");
	S.push("f");
	S.push("g");
	S.print();
	
	cout << endl << endl;
	stack Y = S;
	Y.print();

	string equation, C, stack_str;
	char reply;

	do {
		cout << "Please enter your post fixed operator:" << endl;
		getline(cin, equation);

		C = remove_space(equation);
		stack_str = user_input_validity(C);

		stack list;
		list.build_stack(stack_str);
	
		cout << endl << "If you would like to enter another press y:" << endl;
		cin >> reply;
		cin.ignore();
	} while (reply == 'y' || reply == 'Y');

	return 0;
}

