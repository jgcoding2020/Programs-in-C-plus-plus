
#include <vector> 
#include <string>
using namespace std;

#ifndef vlist_H
#define vlist_H

class vlist
{
public:
	vlist();
	vlist(const vlist&);
	~vlist();
	bool isEmpty();
	vector<string>::iterator search(const string&); 
	void insert(const string&);
	void remove(const string&); 
	void print();
private:
	vector<string> DB;
	int count;
};

#endif


