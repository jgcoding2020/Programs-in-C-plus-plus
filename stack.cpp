#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

/***********************************************************************************/
//Name: destructor
//Precondition: There are no out of scope memory locations
//Postcondition: Out of scope stack memory locations are deleted
//Decription: Deletes values memory locations created that become out of scope
/***********************************************************************************/
stack::~stack()
{
	/*cout<<"Inside !stack \n";*/
	while(s_top!=0)
	{
		pop(); // deletes top of stack
	}
}
/***********************************************************************************/
//Name: Copy constructor 
//Precondition: No copies of data have been needed
//Postcondition: Memory is allocated for copies of data
//Decription: Copies of data have been produced
/***********************************************************************************/
stack::stack(const stack& Org)
{
	/*cout<<"Inside the Copy Constructor\n";*/

	(*this).s_top = 0; // current object value is set to 0

	stack temp; // class object main stack class
	stack_node* p = Org.s_top; // stack pointer points to input stack class object
	while (p != 0) // loop condition stack is not empty
	{
		temp.push(p->data); // adds input argument data to temp class
		p = p->next; // shifts to next node
	}

	p = temp.s_top; // sets p to the top of the stack
	while (p != 0) // condition if list is not empty
	{
		(*this).push(p->data); // adds stack linked list data to current object
		p = p->next; // cycles through list
	}
}
/***********************************************************************************/
//Name: top
//Precondition: stack hasn't had request for data
//Postcondition: request for stack data has been implemented and delivered
//Decription: if the stack has values stored the top of the stack value is returned
/***********************************************************************************/
stack_element stack::top()
{
	/*cout<<"Inside top \n";*/

	if (s_top == 0) // if list is empty end function
	{
		exit(1);
	}
	else
	{
		return s_top->data; // if list has data return top of stack data
	}
}
/***********************************************************************************/
//Name: pop
//Precondition: the top of the stack holds a value
//Postcondition: the new top is the node under the top and old top is deleted
//Decription: deletes the old top and points to the new top that was under the old top
/***********************************************************************************/
void stack::pop()
{
	/*cout<<"Inside pop \n";*/
	stack_node *p; // creates node pointer
	
	if (s_top != 0) // if list has data
	{
		p = s_top; // sets node pointer to top
		s_top = s_top->next; // shifts current pointer to node under top
		delete p; // deletes old top
	}
	
}
/***********************************************************************************/
//Name: push
//Precondition: data needs to be stored in the stack 
//Postcondition: data has been stored in the stack
//Decription: data is added to the top of the stack
/***********************************************************************************/
void stack::push(const stack_element & item)
{
	/*cout<<"Inside push \n";*/
	stack_node *p = new stack_node;	// allocates memory for new node

	p->data = item; // inserts data to new node
	p->next = s_top; // sets new top next address to old top address
	s_top = p; // sets s_top address top address to new top address
}
/***********************************************************************************/
//Name: build_print_stack
//Precondition: no string to be evaluated or stored
//Postcondition: a string has been stored in the stack
//Decription: checks for string validity, removes spaces, stores string in stack
//		with infixed order, and displays stack 
/***********************************************************************************/
void stack::build_print_stack(string& C)
{
	int count = 0, j = 0;
	for (int i = 0; i < C.length(); i++)// loop removes spaces from string
	{
		if (C[i] == ' ')
		{
			count++;
		}

		else
		{
			C[j] = C[i];
			j++;
		}
	}

	C.resize(C.length() - count); // resizes the string with removed spaces

	string str_temp, str_char;
	int root = 0, left = 0, right = 0;
	int operands = 0;
	int operators = 0;
	int str_length = C.length();

	for (int i = 0; i < str_length; i++) // counts operatros and operands in string
	{
		str_temp = C[i];
		if (str_temp == "/" || str_temp == "-" || str_temp == "+" || str_temp == "*")
			operators++;
		else
			operands++;
	}

	if (C != "" && operators >= operands || operators > 3)// invalid conditions return error message
	{
		cout << "Too many operators and not enough operands" << endl;
		return;
	}

	if (operands > operators + 1)// invalid conditions return error message
	{
		cout << "Too many operands and not enough operators" << endl;
		return;
	}

	if (C == "" || str_length == 1 && operands == 1)// identifies unary operand and empty string
	{
		(*this).push(")");
		(*this).push(C);
		(*this).push("(");
	}

	if (operators == 1)// identifies 2 operand with single operator 
	{
		for (int i = 0; i < str_length; i++)// finds and labels the operator
		{
			if (C[i] == '-' || C[i] == '+' || C[i] == '/' || C[i] == '*')
			{
				root = i;
			}
		}

		
		for (int i = str_length; i >= 0; i--)// loops through string from back to front
		{
			if (i == str_length)// adds ) to bottom of stack
			{
				(*this).push(")");
			}

			if (isalpha(C[i]))// adds first operand and root operator to stack with proper spacing
			{
				str_char = C[i];
				(*this).push(str_char);
				(*this).push(" ");
				str_char = C[root];
				(*this).push(str_char);
				(*this).push(" ");
				i--;

				for (i; i >= 0; i--)// adds second operand to stack with proper spacing
				{
					if (isalpha(C[i]))
					{
						str_char = C[i];
						(*this).push(str_char);
						(*this).push("(");
					}
				}
			}
		}
	}

	if (operators == 2)// identifies operation with 2 operators and 3 operands
	{
		for (int i = str_length - 1; i >= 0; i--)// loops to label operators
		{
			if (C[i] == '-' || C[i] == '+' || C[i] == '/' || C[i] == '*')// labels first operator
			{
				right = i;
				i--;

				while (i >= 0)// labels second operators
				{
					if (C[i] == '-' || C[i] == '+' || C[i] == '/' || C[i] == '*')
					{
						left = i;
					}
					i--;
				}
			}
		}

		int count = 0;
		(*this).push(")");
		for (int i = str_length - 1; i >= 0; i--)// loop from back to front of string
		{
			if (isalpha(C[i]))// checks for operand
			{
				str_char = C[i];
				(*this).push(str_char); // pushes operand to stack
				if (count != 2) // allocates proper spacing
				{
					(*this).push(" ");
				}
				count++; // counts operand pushes
			}

			if (count == 1 && C[i] != C[right] && C[i] != C[left])// pushes right operator to stack
			{
				str_char = C[right];
				(*this).push(str_char);
				(*this).push(" ");
			}

			if (count == 2 && C[i] != C[right] && C[i] != C[left])// pushes left operator to stack
			{
				str_char = C[left];
				(*this).push(str_char);
				(*this).push(" ");
			}
		}
		(*this).push("(");
	}

	if (operators == 3)// identifies 4 operand and 3 operator operation
	{
		for (int i = str_length - 1; i >= 0; i--)// loops finds and labels operators
		{
			if (root == 0 && C[i] == '-' || C[i] == '+' || C[i] == '/' || C[i] == '*')
			{
				root = i;// label for root operator
			}

			if (root != 0 && C[i] == '-' || C[i] == '+' || C[i] == '/' || C[i] == '*')
			{
				right = i;// label for right operator
			}

			if (right != 0 && C[i] == '-' || C[i] == '+' || C[i] == '/' || C[i] == '*')
			{
				left = i;// label for left operator
			}
		}

		(*this).push(")");
		(*this).push(")");

		for (int i = str_length - 1; i >= 0; i--)// loops from back to front of string
		{
			if (isalpha(C[i]))// checks for operand
			{
				str_char = C[i];
				(*this).push(str_char);
				if (count != 3)// allocates proper spacing
				{
					(*this).push(" ");
				}
				count++;// counts operands
			}

			if (count == 2)// pushes front ( appropriately 
			{
				(*this).push("(");
				(*this).push(" ");
			}

			if (count == 1 && C[i] != C[right] && C[i] != C[root] &&C[i] != C[left])
			{
				str_char = C[right];
				(*this).push(str_char);// pushes right operator
				(*this).push(" ");
			}

			if (count == 2 && C[i] != C[right] && C[i] != C[root] && C[i] != C[left])
			{
				str_char = C[root];
				(*this).push(str_char);// pushes root operator
				(*this).push(" ");
			}

			if (count == 2)// pushes back ) appropriately
			{
				(*this).push(")");
				(*this).push(" ");
			}

			if (count == 3 && C[i] != C[right] && C[i] != C[root] && C[i] != C[left])
			{
				str_char = C[left];
				(*this).push(str_char);// pushes left operator
				(*this).push(" ");
			}
		}
		(*this).push("(");
		(*this).push("(");
	}

	for (stack_node* p = s_top; p != 0; p = p->next) // loops through linked list
	{
		cout << p->data; //  displays linked list data from top to bottom
	}
	cout << endl;
}		   	
