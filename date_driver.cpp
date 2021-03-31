#include "date.h"

//*********************************************************************************************
//*********************************************************************************************
//	D A T E	D R I V E R . C P P




//EXAMPLE OF PROGRAM HEADER
/********************************************************************************************

Name:	Joshua Gardner Z#: 15117842
Course: Date Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date:	1/29/2021 Due Time: 11:59pm
Total Points: 100 Assignment 3: Date program

Description: This program evaluates the validity of dates given and whether or not the date 
is a leap year and displays the results 


*********************************************************************************************/


int main()
{

	Date myDate;
	Date herDate(11, 14, 1953);
	Date test1Date(25, 1, 1982); //should generate error message that bad month
	Date test22Date(2, 29, 2020); //ok, should say leep year
	Date test3Date(2, 30, 2021); //should generate error message that bad day
	Date test4Date(1, 25, 0000); //should generate error message that bad year
	Date test5Date(80, 40, 0000); //should generate error message that bad month, day and year

	herDate.display();
	cout << herDate.getMonth() << endl;
	cout << herDate.getDay() << endl;
	cout << herDate.getYear() << endl;
	myDate.setMonth(11);
	myDate.setDay(12);
	myDate.setYear(2015);
	cout << "myDate: " << myDate << " test22Date: " << test22Date << " herDate: " << herDate << endl;

	return 0;

}