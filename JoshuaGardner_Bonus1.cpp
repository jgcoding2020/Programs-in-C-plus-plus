/*
Name: Joshua Gardner
Course: COP 3014
Assignment: Lab1
Purpose: converting mph into a runner's pace given in minutes and seconds
Date: 9/18/2020
*/

#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    // declare variables
    // seconds, minutes, total, inputs
    double treadmill_output = 0, total_seconds = 0, seconds = 0, minutes = 0;
    char exit;

    do
    {

    // get input from user
    cout << "Please enter the output displayed on your treadmill in mph:\n" << endl;
    cin >> treadmill_output;

    // conversion
    total_seconds = 3600 / treadmill_output; // 553.846
    minutes = total_seconds / 60; // 9.231
    seconds = total_seconds - static_cast <int> (minutes) * 60; // 553.846 - (9 * 60 = 540) = 13.846

    //output results to user
    cout << "\nYour pace is " << static_cast <int> (minutes) << " minutes " << seconds << " seconds." << endl;
    cout << "\nDo you want to continue? If yes press y, or press any other key to exit.\n" << endl;
    cin >> exit;

    } while (exit == 'y' || exit == 'Y');

    cout << "\nThank you for using Treadmill converter." << endl;

    return 0;
}

/*
Name: Joshua Gardner
Course: COP 3014
Assignment: Bonus1
Purpose: A program that plays the game mad lib
Date: 9/18/2020
*/

/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // declare variables
    string instructor_name, your_name, food, adjective, color, animal;
    int number;
    bool boolean;

    // user input
    cout << "Please enter your instructor's name:" << endl;
    cin >> instructor_name;

    cout << "\nPlease enter your name:" << endl;
    cin >> your_name;

    cout << "\nPlease enter a food:" << endl;
    cin >> food;

    cout << "\nPlease enter a number between 100 and 120:" << endl;
    cin >> number;

    cout << "\nPlease enter a color:" << endl;
    cin >> color;

    cout << "\nPlease enter an animal:" << endl;
    cin >> animal;

    cout << "\nPlease enter an adjective:" << endl;
    cin >> adjective;

    cout << "\nPlease enter 'true' or 'false':" << endl;
    cin >> boolean;

    // output to user including variable values input by user
    cout << "\nDear Professor " << instructor_name << ",\n\n"
    "I am sorry that I am unable to turn in my homework at this time.\n"
    "First, I ate a rotten " << food << ", which made me turn " << color << " and extremely\n"
    "ill. I came down with a fever of " << number << ". Next, "
    "my " << adjective << " pet " << animal << " must have \nsmelled the remains "
    "of the " << food << " on my homework, because he ate it. \nI am currently "
    "rewriting my homework and hope you will accept it late. \nI promise this "
    "letter is " << boolean << ".\n\n"
    "Sincerely,\n\n"
    << your_name << endl;

    return 0;
}
*/
