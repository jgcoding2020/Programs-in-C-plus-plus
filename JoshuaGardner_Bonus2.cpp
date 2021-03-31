/*
Name Joshua Gardner Z15117842
Course: COP 3014
Assignment: Lab2
Purpose: Use of functions to convert weight measurement types
Date: 10/10/2020
*/

#include <iostream>

using namespace std;
// function prototype for user input values
double user_input(int &num, double &lbs, double &oz, double &kilos, double &gr);
// function prototype for converting pounds and ounces into kilograms
double conversion1(double lbs, double oz, double &kilos);
// function prototype for converting kilograms and grams into pounds
double conversion2(double &lbs, double kilos, double grs);
// function prototype that outputs either pounds or kilograms
int output(int num, double lbs, double kilos);

int main()
{
    // main scope variable initializations/ declarations
    int choice = 0;
    double user_choice = 0, convert_pounds = 0, convert_output = 0, convert_kilograms = 0;
    double pounds = 0, ounces = 0, kilograms = 0, grams = 0;
    // function call by reference for user input data
    user_choice = user_input(choice, pounds, ounces, kilograms, grams);
    // place value setting for output values
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    // branch statement executes functions based on user input choice
    if (choice == 1)
    {
        convert_pounds = conversion1(pounds, ounces, kilograms);
        convert_pounds;
        convert_output = output(choice, pounds, kilograms);
        convert_output;
    }
    else if (choice == 2)
    {
        convert_kilograms = conversion2(pounds, kilograms, grams);
        convert_kilograms;
        convert_output = output(choice, pounds, kilograms);
        convert_output;
    }
    return 0;
}
// user input function
double user_input(int &num, double &lbs, double &oz, double &kilos, double &grs)
{
    bool key = 0;
    do {
        cout << "To convert from pounds and ounces to kilograms:" << endl;
        cout << "Press 1:" << endl;
        cout << "To convert kilograms and grams to pounds:" << endl;
        cout << "Press 2:" << endl;
        cin >> num;
        if (num == 1 || num == 2)
            key = true;
        switch (num)
        {
            case 1:
                cout << "Please enter weight in pounds:";
                cin >> lbs;
                cout << "Please enter weight in ounces:";
                cin >> oz;
                break;
            case 2:
                cout << "Please enter weight in kilograms:";
                cin >> kilos;
                cout << "Please enter weight in grams:";
                cin >> grs;
                break;
            default:
                num = 0;
                break;
        }
    } while (key == false);

    return num;
}
// function converting pounds and ounces to kilograms
double conversion1(double lbs, double oz, double &kilos)
{
    double kilograms;
    kilograms = (lbs + oz/16)/2.2046;
    kilos = kilograms;
    return kilos;
}
// function converting kilograms and grams to pounds
double conversion2(double &lbs, double kilos, double grs)
{
    double pounds, ounces;
    pounds = (kilos + grs/1000) * 2.2046;
    lbs = pounds;
    return lbs;
}
// function that outputs pounds or kilograms based on the users choice
int output(int num, double lbs, double kilos)
{
    switch (num)
    {
        case 1:
            cout << "Your converted results are " << kilos << endl;
            break;
        case 2:
            cout << "Your converted results are " << lbs << endl;
            break;
        default:
            break;
    }
    return num;
}

// There are 2.2046 pounds in a kilogram, 1000 grams in a kilogram, and 16 ounces in a pound.
