/*
Name: Joshua Gardner Z15117842
Course: COP 3014 003
Assignment: Assignment 2
Purpose: To collect 10 user entered numbers and calculate
sums and averages of positive, negative, and all entries
Date: 9/19/2020
*/

#include <iostream>

using namespace std;

int main()
{
    // variable declarations/ initialization
    int counter = 1, avg_pos_counter = 0, avg_neg_counter = 0,avg_all_counter = 0;
    double user_entry, sum_pos = 0, avg_pos = 0, sum_neg = 0, avg_neg = 0, sum_all = 0, avg_all = 0;

    cout << "Please enter 10 numbers: \n";

    // loop that collects user entry data and changes values of variables accordingly
    do {
        cin >> user_entry;
        if (user_entry > 0)
            {
            sum_pos += user_entry;
            avg_pos_counter++;
            avg_all_counter++;
            counter++;
            }
        else if (user_entry < 0)
            {
            sum_neg += user_entry;
            avg_neg_counter++;
            avg_all_counter++;
            counter++;
            }
        else
            {
            avg_all_counter++;
            counter++;
            }
    } while (counter <= 10);

    // performs calculations on categorized user entered data and stores data in appropriate variables
    avg_pos = sum_pos / avg_pos_counter;
    avg_neg = sum_neg / avg_neg_counter;
    sum_all = sum_pos + sum_neg;
    avg_all = sum_all / avg_all_counter;

    // displays sums and averages of positive, negative, and all user entered values
    cout << "The sum of the positive entries is " << sum_pos << ".\n";
    if (avg_pos_counter > 0)
        cout << "The average of the positive entries is " << avg_pos << ".\n";
    else
        cout << "The average of the positive entries is 0.\n";
    cout << "The sum of the negative entries is " << sum_neg << ".\n";
    if (avg_neg_counter > 0)
        cout << "The average of the negative entries is " << avg_neg << ".\n";
    else
        cout << "The average of the negative entries is 0.\n";
    cout << "The sum of all entries is " << sum_all << ".\n";
    if (avg_all_counter > 0)
        cout << "The average of all entries is " << avg_all << ".\n";
    else
        cout << "The average of the all entries is 0.\n";
    return 0;
}
