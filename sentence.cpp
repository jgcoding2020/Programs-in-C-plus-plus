#include <iostream>
#include <string>
#include "sentence.h"

sentence::sentence()
{
	front = back = 0;
}

int sentence::length()
{
	int string_length = 0;
	word* picked = this->front;

	if (picked == 0)
	{
		return string_length;
	}
	else
	{
		while (picked != 0)
		{
			string_length += picked->term.length();
			picked = picked->next;
		}
		return string_length;
	}
}

ostream& operator<<(ostream& out, const sentence& A)
{
	word* temp;
	
	for (temp = A.front; temp != 0; temp = temp->next)
	{
		out << temp->term;
	}
	return out;
}

sentence::sentence(const string& s)
{
	front = 0;
	back = 0;
	int length = s.length();

	if (length == 0)
	{
		front = 0;
		return;
	}

	string temp, space;
	space = " ";
	for (int i = 0; i < length; i++)
	{
		if (s[i] != ' ')
		{
			temp += s[i];
		}

		if (s[i] == ' ')
		{
			add_back(temp);
			add_back(space);
			temp = "";
		}

		if (s[i + 1] == '\0')
		{
			add_back(temp);
		}
	}
}

sentence::sentence(const sentence& org)
{
	front = 0;
	back = 0;

	word* node = org.front;

	while (node != 0)
	{
		add_back(node->term);
		node = node->next;
	}
}

bool sentence::isEqual(sentence& B)
{
	if (length() != B.length())
	{
		return false;
	}

	word* ptrA = new word;
	word* ptrB = new word;

	ptrA = front;
	ptrB = B.front;

	while (ptrA != 0 && ptrB != 0)
	{
		
		if (ptrA->term != ptrB->term)
		{
			return false;
		}

		ptrA = ptrA->next;
		ptrB = ptrB->next;
	}

	
	return true;
}

void sentence::operator=(const string& s)
{
	front = 0;
	back = 0;
	int length = s.length();

	if (length == 0)
	{
		front = 0;
		return;
	}

	string temp, space;
	space = " ";
	for (int i = 0; i < length; i++)
	{
		if (s[i] != ' ')
		{
			temp += s[i];
		}

		if (s[i] == ' ')
		{
			add_back(temp);
			add_back(space);
			temp = "";
		}

		if (s[i + 1] == '\0')
		{
			add_back(temp);
		}
	}
}

sentence::~sentence()
{
	cout << "Destructor has been called\n";
	word* remove_node = front;

	while (remove_node != 0) {
		word* next = remove_node->next;
		delete remove_node;
		remove_node = next;
	}
	front = 0;
}

void sentence::add_back(string& s)
{
	if (front == 0)
	{
		front = new word;
		front->term = s;
		front->next = 0;
		back = front;
	}

	else
	{
		word* p = new word;
		p->next = 0;
		p->term = s;
		back->next = p;
		back = p;
	}
}

void sentence::operator+(sentence& B)
{
	word* addList = B.front;

	if (addList != 0)
	{
		while (addList != 0)
		{
			add_back(addList->term);
			addList = addList->next;
		}
	}

	else
	{
		return;
	}
}

word* sentence::search(const string& s)
{

	word* p = front;
						

	while (p != 0)  
	{
		if (p->term == s) 
		{
			return p;       
		}
		p = p->next; 
	}
	return p; 
}

void sentence::remove(const string& s)
{
	word* p = search(s);						
	if (p == 0)							
	{
		return;
	}
	else								
	{									
		if (p == front && front == back)
		{
			delete p;
			front = back = 0;
		}								
		else if (p == front)
		{
			front = front->next;
			delete p;
		}								
		else
		{
			word* back_ptr = front;		
			while (back_ptr != 0 && back_ptr->next != p)
			{
				back_ptr = back_ptr->next;
			}

			if (p == back)
			{
				back = back_ptr;
			}

			back_ptr->next = p->next;
			delete p;
		}
	}
}

sentence& sentence::operator=(const sentence& w)
{
	front = 0;
	back = 0;

	word* ptrA = w.front;

	while (ptrA != 0)
	{
		add_back(ptrA->term);
		ptrA = ptrA->next;
	}
	
	return *this;
}