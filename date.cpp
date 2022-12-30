#include "date.h"

//*************************************************************************************
//Name:	Date default constructor
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to a date
//Description: This is the default constructor which will be called automatically when
//	an object is declared. It will initialize the state of the class
//
//*************************************************************************************
Date::Date()
{
	int month = 01;
	int day = 01;
	int year = 0001;

	cout << "Default constructor has been called" << endl;
	cout << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(2) << day;
	cout << "/" << setfill('0') << setw(4) << year << endl << endl;
}


//*************************************************************************************
//Name:	Date Explicit-Value constructor
//Precondition: Class Date object's states have not been initialized
//Postcondition: Class Date object's states have been initialized
//Description: initializes class Date object's states
//
//
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	myMonth = m;
	myDay = d;
	myYear = y;

	cout << "Explicit-value constructor has been called" << endl;
	display();
}

//*************************************************************************************
//Name: Member function	Display 
//Precondition: Class Date objects have not been displayed
//Postcondition: Class Date objects have been displayed
//Description: Displays whether a class Date object's date state is valid or not
//
//
//*************************************************************************************
void Date::display()
{
	// if leap year is true displays 02/29/#### as a valid leap year date
	if (getMonth() == 2 && getDay() == 29 && getLeapYear() == 1)
	{
		cout << setfill('0') << setw(2) << myMonth << "/" << setfill('0') << setw(2) << myDay;
		cout << "/" << setfill('0') << setw(4) << myYear << endl;

		cout << "This is a leap year" << endl;
	}

	//if the combination of month, day, and year are valid the date is displayed 
	else if (getMonth() != -1 && getDay() != -1 && getYear() != -1)
	{
		cout << setfill('0') << setw(2) << myMonth << "/" << setfill('0') << setw(2) << myDay;
		cout << "/" << setfill('0') << setw(4) << myYear << endl;

		if (getLeapYear() == 1)
			cout << "This is a leap year" << endl;
	}

	// The following if statements display dates invalid based on month, day, and/ or year
	if (getMonth() == -1 && myMonth != 25)
		cout <<  "Month = " << setfill('0') << setw(2) << myMonth << " is incorrect" << endl;

	if (getMonth() == -1 && myMonth == 25)
		cout << "Month = " << setfill('0') << setw(2) << myMonth << " is incorrect";

	if (getDay() == -1)
		cout << "Day = " << setfill('0') << setw(2) << myDay << " is incorrect" << endl;

	if (getYear() == -1)
		cout << "Year = " << setfill('0') << setw(4) << myYear << " is incorrect" << endl;

	cout << endl;
}

//*************************************************************************************
//Name:	Member function accessor getMonth
//Precondition: Class Date object's months have not been accessed and returned
//Postcondition: Class Date object's months have been accessed and returned
//Description: Accesses and returns the class Date object's months if in a valid range or -1
//	if month range is invalid
//
//*************************************************************************************
int Date::getMonth()
{
	if (myMonth < 1 || myMonth > 12)
		return -1;

	else
		return myMonth;
}

//*************************************************************************************
//Name:	Member function accessor getDay
//Precondition: Class Date object's days have not been accessed and returned
//Postcondition: Class Date object's days have been accessed and returned
//Description: Accesses and returns the class Date object's days if in a valid range
//	or -1 if the day/ month combination range is invalid
//
//*************************************************************************************
int Date::getDay()
{
	if (myDay < 1 || myDay > 31)
		return -1;

	else if (myDay == 31 && (myMonth == 11 || myMonth == 9 || myMonth == 6 || myMonth == 4 || myMonth == 2))
		return -1;

	else if (myMonth == 2 && myDay == 30)
		return -1;

	else
		return myDay;
}

//*************************************************************************************
//Name:	Member function accessor getYear
//Precondition: Class Date object's years have not been accessed and returned
//Postcondition: Class Date object's years have been accessed and returned
//Description: Accesses and returns the class Date object's years if in a valid range
//	or -1 if the year's range is invalid
//
//*************************************************************************************
int Date::getYear()
{
	if (myYear >= 0001)
		return myYear;

	else
		return -1;
}

//*************************************************************************************
//Name: Member function mutator setMonth
//Precondition: Class Date object's months are not set
//Postcondition: Class Date object's months are set
//Description: Sets the state of the class Date object's months
//
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	myMonth = m;
}

//*************************************************************************************
//Name: Member function mutator setDay
//Precondition: Class Date object's days are not set
//Postcondition: Class Date object's days are set
//Description: Sets the state of the class Date object's days
//
//
//*************************************************************************************
void Date::setDay(unsigned d)
{
	myDay = d;
}

//*************************************************************************************
//Name: Member function mutator setYear
//Precondition: Class Date object's years are not set
//Postcondition: Class Date object's Years are set
//Description: Sets the state of the class Date object's years
//
//
//*************************************************************************************
void Date::setYear(unsigned y)
{
	myYear = y;
}

//*************************************************************************************
//Name: Friend member function ostream & operator
//Precondition: Private class Date variables are not accessable through ostream directly
//Postcondition: Private class Date variables are accessable through ostream directly
//Description: Allows direct access to class Date varibles through ostream
//
//
//*************************************************************************************
ostream& operator<<(ostream& out, Date& dateObj)
{

	out << setfill('0') << setw(2) << dateObj.myMonth << "/" << setfill('0') << setw(2) << dateObj.myDay;
	out << "/" << setfill('0') << setw(4) << dateObj.myYear;
	
	return out;

}

//*************************************************************************************
//Name: Class Date member function getLeapYear
//Precondition: Leap years are not identified in class Date object states
//Postcondition: Leap years are identified in class Date objects states
//Description: Recognizes and returns if a leap year is valid or not within a class Date object state 
//
//
//*************************************************************************************
int Date::getLeapYear()
{	
	//nested if statements that use remainders to calculate leap year validity
	if (myYear % 4 == 0)
	{
		if (myYear % 100 == 0)
		{
			if (myYear % 400 == 0)
			{
				return 1;
			}
			else
				return -1;
		}
		else
			return 1;
	}
	else
		return -1;
}
