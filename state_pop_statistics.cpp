#include <iostream>
#include <fstream>
#include <string>
#include "state.h"

using namespace std;

/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Joshua Gardner Date:  01/22/2021
Description:  The program manages a dynamic array of records.
******************************************************************************************************************************************************/

int main()
{
	cout << "***********************************************************************************\n";
	cout << "TEST 1:  Testing the default constructor, Is_Full, double_size, and Print_ALL\n\n";
	cout << "***********************************************************************************\n";
	state_class S;
	cout << endl;
	S.Print_ALL();
	cout << endl;
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 1:\n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;

	cout << "***********************************************************************************\n";
	cout << "TEST 2:  Testing the Remove, Is_Empty, Search, and Print_ALL\n\n";
	cout << "***********************************************************************************\n";
	S.Remove("Alabama");
	S.Remove("Florida");
	S.Remove("Wyoming");
	cout << endl;
	S.Print_ALL();
	cout << endl;
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 2:\n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;

	cout << "***********************************************************************************\n";
	cout << "TEST 3 Testing operator+, Is_Full, double_size, and Print_ALL\n\n";
	cout << "***********************************************************************************\n";
	population_record r;
	r.state_name = "Alabama";
	r.population = 1111111;
	S + r;
	r.state_name = "Florida";
	r.population = 99999999;
	S + r;
	r.state_name = "Wyoming";
	r.population = 222222;
	S + r;
	cout << endl;
	S.Print_ALL();
	cout << endl;
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 3: \n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;


	cout << "***********************************************************************************\n";
	cout << "TEST 4:  Testing Print_Range\n\n";
	cout << "***********************************************************************************\n";
	int min = 500000, max = 1500000;
	cout << "List of States with Population Sizes between " << min << " and " << max << " inclusive "<<endl << endl;
	cout << endl;
	S.Print_Range(min, max);
	cout << endl;
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 4:\n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;

	cout << "***********************************************************************************\n";
	cout << "TEST 5:  Testing State_Count\n\n";
	cout << "***********************************************************************************\n";
	min = 500000;
	max = 1500000;
	cout << endl;
	cout << "Number of States with Population Sizes between " << min << " and " << max << " (inclusive) = " << S.State_Count(min, max);
	cout << endl;
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 5:\n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;

	cout << "***********************************************************************************\n";
	cout << "TEST 6:  copy constructor and Print_ALL\n\n";
	cout << "***********************************************************************************\n";
	state_class New = S;
	cout << endl;
	New.Print_ALL();
	cout << endl;
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 6:\n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;

	cout << "***********************************************************************************\n";
	cout << "TEST 7:  Sort and Print_ALL\n\n";
	cout << "***********************************************************************************\n";
	New.Sort();
	cout << endl;
	New.Print_ALL();
	cout << endl;
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 7:\n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;

	cout << "***********************************************************************************\n";
	cout << "TEST 8:  Print_ALL_To_File\n\n";
	cout << "***********************************************************************************\n";
	New.Print_ALL_To_File("state_data_update.txt");
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 8:\n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;
	
	return 0;
}
