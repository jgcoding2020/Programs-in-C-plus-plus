#include <iostream>
#include <string>

using namespace std;

#ifndef SENTENCE_H
#define SENTENCE_H

class word
{
public:
	string term;
	word* next;
};

class sentence
{
public:
	sentence();	//The default constructor will initialize your state variables. 
				//The front of the linked list is initially set to NULL or 0; this implies a non-header node 
				//implementation of the link list.
	sentence(const string& s);//Explicit-value constructor: This constructor will have one argument; 
							//a C-style string or a C++ string representing the word to be created;
	sentence(const sentence& org);// Copy Constructor: Used during a call by value, return, or initialization/declaration of a word object;
	~sentence();//Destructor: The destructor will de-allocate all memory allocated for the word. Put the message 
								//"destructor called\n" inside the body of the destructor.
	bool isEmpty() { return front == 0; }//inline implementation
	
	int length();//Length: Determines the length of the word A; remember A is the current object;
	
	void add_back(string& s);// Adds a string to the back of the linked list
	friend ostream& operator<<(ostream& out, const sentence& A); //Overload the insertion operator as a friend function with chaining to print a word A;
	void operator=(const string& s);// Overload the assignment operator as a member function to take a 
									//string (C-style or C++ string, just be consistent in your implementation) as an argument and 
									//assigns its value to A, the current object;
	sentence& operator=(const sentence& w);// Overload the assignment operator as a member function with chaining to take a word 
											//object as an argument and assigns its value to A, the current object;
	void operator+(sentence& B);//Overload the ‘+” operator as a member function without chaining to add word B 
								//(adds the set of symbols that makep B's linked list to the back of A's linked list) to the back of word A; 
								//remember A is the current object;
	bool isEqual(sentence& B);// Returns true if two word objects are equal; otherwise false; remember A is the current
	void remove(const string& s);//Deletes the first occurrence of the string s from the list A;
	word* search(const string& s);//Searches for a matching string stored in the linked list
private:
	word* front, * back;
};

#endif
