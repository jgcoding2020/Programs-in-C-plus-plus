
#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

stack::~stack()
{
	/*cout<<"Inside !stack \n";*/
	while(s_top!=0)
	{
		pop(); // deletes top of stack
	}
}

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

void stack::push(const stack_element & item)
{
	/*cout<<"Inside push \n";*/
	stack_node *p = new stack_node;	// allocates memory for new node

	p->data = item; // inserts data to new node
	p->next = s_top; // sets new top next address to old top address
	s_top = p; // sets s_top address top address to new top address
}

void stack::print()
{
	/*cout<<"Inside print \n";*/

	for(stack_node *p = s_top; p!=0; p=p->next) // loops through linked list
	{
		cout<<p->data<<endl; //  displays linked list data from top to bottom
	}
}

string user_input_validity(string& C)
{
		string str_temp;
		int operands = 0;
		int operators = 0;
		int str_length = C.length();

		for (int i = 0; i < str_length; i++)
		{
			str_temp = C[i];
			if (str_temp == "/" || str_temp == "-" || str_temp == "+" || str_temp == "*")
				operators++;
			else
				operands++;
		}

		if (C == "")
		{
			return C;
		}

		if (str_length == 1)
		{
			if (operators >= operands)
			{
				cout << "too many operators and not enough operands" << endl;
				C.resize(str_length - str_length);
				return C;
			}

			if (operands >= operators)
			{
				return C;
			}
		}

		if (operands > operators)
		{
			if (str_length == 3 && C[2] == '/' || C[2] == '*' || C[2] == '-' || C[2] == '+')
			{
				return C;
			}

			
			else if (str_length == 7 && C[2] == '/' || C[2] == '*' || C[2] == '-' || C[2] == '+')
			{
				
				if (str_length == 7 && C[5] == '/' || C[5] == '*' || C[5] == '-' || C[5] == '+')
				{
					//if (str_length == 7 && C[6] == '/' || C[6] == '*' || C[6] == '-' || C[6] == '+')
						return C;
				}
			}

			else
			{
				cout << "too many operands and not enough operators" << endl;
				C.resize(str_length - str_length);
				return C;
			}
		}

		if (operators < operands)
		{
			if (str_length == 7 && C[2] == '/' || C[2] == '*' || C[2] == '-' || C[2] == '+')
			{
				if (C[5] == '/' || C[5] == '*' || C[5] == '-' || C[5] == '+')
				{
					if (C[6] == '/' || C[6] == '*' || C[6] == '-' || C[6] == '+')
						return C;
				}
			}

			else if (str_length == 3 && (C[2] == '/' || C[2] == '*' || C[2] == '-' || C[2] == '+'))
			{
				return C;
			}

			else
			{
				cout << "too many operands and not enough operators" << endl;
				C.resize(str_length - str_length);
				return C;
			}
		}

		if (C[0] == '/' || C[0] == '*' || C[0] == '-' || C[0] == '+')
		{
			cout << "too many operators and not enough operands" << endl;
			C.resize(str_length - str_length);
			return C;
		}

		if (C[1] == '/' || C[1] == '*' || C[1] == '-' || C[1] == '+')
		{
			cout << "too many operators and not enough operands" << endl;
			C.resize(str_length - str_length);
			return C;
		}

		if (C[3] == '/' || C[3] == '*' || C[3] == '-' || C[3] == '+')
		{
			cout << "too many operators and not enough operands" << endl;
			C.resize(str_length - str_length);
			return C;
		}

		if (C[4] == '/' || C[4] == '*' || C[4] == '-' || C[4] == '+')
		{
			cout << "too many operators and not enough operands" << endl;
			C.resize(str_length - str_length);
			return C;
		}

		if (operators < operands - 1)
		{
			cout << "too many operands and not enough operators" << endl;
			C.resize(str_length - str_length);
			return C;
		}

		if (operands <= operators)
		{
			cout << "too many operators and not enough operands" << endl;
			C.resize(str_length - str_length);
			return C;
		}

		if (str_length == 1 && (C != "/" || C != "*" || C != "-" || C != "+"))
		{
			return C;
		}

		if (str_length == 3 && C[2] == '/' || C[2] == '*' || C[2] == '-' || C[2] == '+')
		{
			return C;
		}

		if (str_length == 7 && C[2] == '/' || C[2] == '*' || C[2] == '-' || C[2] == '+')
		{
			if (C[5] == '/' || C[5] == '*' || C[5] == '-' || C[5] == '+')
			{
				if (C[6] == '/' || C[6] == '*' || C[6] == '-' || C[6] == '+')
					return C;
			}
		}

		C.resize(str_length - str_length);
		return C;
}

string remove_space(string equation)
{
	int count = 0, j = 0;
	for (int i = 0; i < equation.length(); i++)
	{
		if (equation[i] == ' ')
		{
			count++;
		}

		else
		{
			equation[j] = equation[i];
			j++;
		}
	}

	equation.resize(equation.length() - count);

	return equation;
}

void stack::build_stack(const string& C)
{
	int i = 0, str_length;
	str_length = C.length();
	string str_char;

	if (str_length != 3 && str_length != 7)
	{
		if (str_length == 1)
		{
			(*this).push(")");
			(*this).push(C);
			(*this).push("(");
		}
		else
			(*this).push("");
	}

	if (str_length == 3)
	{
		(*this).push(")");
		str_char = C[1];
		(*this).push(str_char);
		(*this).push(" ");
		str_char = C[2];
		(*this).push(str_char);
		(*this).push(" ");
		str_char = C[0];
		(*this).push(str_char);
		(*this).push("(");
	}

	if (str_length == 7)
	{
		(*this).push(")");
		(*this).push(")");
		str_char = C[4];
		(*this).push(str_char);
		(*this).push(" ");
		str_char = C[5];
		(*this).push(str_char);
		(*this).push(" ");
		str_char = C[3];
		(*this).push(str_char);
		(*this).push("(");
		(*this).push(" ");
		str_char = C[6];
		(*this).push(str_char);
		(*this).push(" ");
		(*this).push(")");
		str_char = C[1];
		(*this).push(str_char);
		(*this).push(" ");
		str_char = C[2];
		(*this).push(str_char);
		(*this).push(" ");
		str_char = C[0];
		(*this).push(str_char);
		(*this).push("(");
		(*this).push("(");
	}

	for (stack_node* p = s_top; p != 0; p = p->next) // loops through linked list
	{
		cout << p->data; //  displays linked list data from top to bottom
	}
	cout << endl;
}		   	


	

		



	

	




