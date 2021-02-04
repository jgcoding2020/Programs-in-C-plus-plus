#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class string_class {

public:
	string_class(); // default constructor initialzes class private variable 
	string_class(string string_in); // explicit constructor initializes class object argument
	bool palindrome(); // class bool member function returns true if argument string = palindrome
	void replace_all(string oldstring, string new_string); // member funtion replaces parts of current string  
	friend ostream& operator<<(ostream& out, string_class& string_class_obj);//overloaded operator<< as a friend function with chaining
	bool match(string& current_string, string& old_string, int& i);
private:
	string current_string; // private member variable
};
