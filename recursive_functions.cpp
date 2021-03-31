#include <iostream>
#include <string>

using namespace std;

//********************************************************************************************
//Name:	Joshua Gardner		Z#:	15117842
//Course: Date Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
//Due Date:	3/26/2021	Due Time:	11:59pm
//Total Points: 25 Assignment module 10: recursion program
//Description: tests if input string is a palindrome and use of recursive functions
//*********************************************************************************************

bool palindrome(const string& s);//tests if string is a palindrome recursively
string printReversel(string& s);//returns reversed string recursively
string printIterReverse(string& s);//returns reversed string non recursively

int main()
{
	string s;// holds user input string value
	string response;// loop condition key
	
	do {
		cout << "Please enter a string to test:" << endl;
		cout << "You entered: ";
		getline(cin, s);
		if (s != "")
		{
			cout << "****************************** Test One ******************************\n";
			cout << "**********************************************************************\n";
			if (palindrome(s))// palindrome test/ responses
				cout << "\nA recursive function found \"" << s << "\" is a palindrome." << endl;
			else
				cout << "\nA recursive function found \"" << s << "\" is not a palindrome." << endl;
			cout << "\n**************************** End Test One ****************************\n";
			cout << "**********************************************************************\n";
			cout << "\n****************************** Test Two ******************************\n";
			cout << "**********************************************************************\n";
			cout << endl <<"Your string \"" << s << "\" is going to be reversed by a recursive function." << endl;
			string recursiveReversal;
			cout << "Your string \"" << s << "\" has been reversed: ";
			recursiveReversal = printReversel(s);//recursive reversal of string
			cout << "\"" << recursiveReversal << "\"" << endl;
			cout << "\n***************************** Test Three *****************************\n";
			cout << "**********************************************************************\n";
			cout << endl << "Your string \"" << s << "\" is going to be reversed by a non recursive function.";
			string nonRecursiveReversal;//non recursive reversal of string
			nonRecursiveReversal = printIterReverse(s);
			cout << "\n*************************** End Test Three ***************************\n";
			cout << "**********************************************************************\n";
		}

		else
			cout << "You entered an empty string, there is nothing to test..." << endl;
		cin.clear();//clears cin of \n for next getline success
		cout << endl << "Would you like to test another string? Y or N:" << endl;
		getline(cin, response);
	} while (response != "n" && response != "N");
	
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: palindrome
//Precondition: string needs to be recursively tested
//Postcondition: string has been recursively tested
//Description: returns true or false based on string palindrome validity
///////////////////////////////////////////////////////////////////////////////////////////////

bool palindrome(const string& s)
{
	string paliString;// holds substring producing iteration
	if (s.length() == 0 || s.length() == 1)// determines if the iteration is necessary
	{
		return true;
	}

	else if (toupper(s[0]) == toupper(s[s.length() - 1]))//tests front and back of string for equality
	{
		paliString = s.substr(1, s.length() - 2);//shrinks string on both ends by 1
		return palindrome(paliString);//recursive function call
	}

	else// evaluate string != palindrome
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: printReversel
//Precondition: string needs to be reversed recursively
//Postcondition: string is reversed recursively
//Description: input string is reversed in a recursive manner
///////////////////////////////////////////////////////////////////////////////////////////////

string printReversel(string& s)
{
	if (s.length() == 0 || s.length() == 1)// evaluates no need for recursive call
	{
		return s;
	}
	else
	{
		string shrinkString = s.substr(0, s.length() - 1);//shrinks back of string by one
		return s[s.length() - 1] + printReversel(shrinkString);//returns back of string + recursive call
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: printIterReverse
//Precondition: string needs to be reversed non recursively
//Postcondition:string has been reversed non recursively
//Description: input string is returned reversed non recursively
///////////////////////////////////////////////////////////////////////////////////////////////

string printIterReverse(string& s)
{
	string temp = s;
	int j = 0;

	for (int i = s.length() - 1; i >= 0; i--)
	{// non recursively reverses string
		s[j] = temp[i];// j is front (increments) i is back (decrements)
		j++;
	}
	cout << "\n\"" << s<< "\"" << " has been reversed." << endl;
	
	return s;// returns reversed string
}