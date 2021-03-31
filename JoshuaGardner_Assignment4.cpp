/*
Name: Joshua Gardner Z15117842
Course: COP3014
Assignment: Assignment 4
Purpose: Using functions to create a given amount of change
Date: 10/13/2020
*/

#include <iostream>

using namespace std;

int user_request(int &change, int &total_change);
//function requesting user to enter amount of change
void compute_coins(int coin_value, int &num, int &amount_left);
//function that calculates how many of each type of coin is required for efficient change return
int change_result(int total_change, int num_quar, int num_dim, int num_nick, int num_pen);
//function that displays change results
int try_again(int &choice, bool &repeat);
//function that repeats entire process upon user request
int main()
{
    //main scope variables
    int total_change, remainder, choice, quarters = 25, dimes = 10, nickels = 5, pennies = 1;
    int num_quar, num_dim, num_nick, num_pen;
    int user_input, change_output, repeat_process;
    bool repeat;
    //loop that continues to execute functions under boolean condition
    do {
        repeat = false;
        user_input = user_request(remainder, total_change);
        user_input;
        num_quar = remainder;
        compute_coins(quarters, num_quar, remainder);
        num_dim = remainder;
        compute_coins(dimes, num_dim, remainder);
        num_nick = remainder;
        compute_coins(nickels, num_nick, remainder);
        num_pen = remainder;
        compute_coins(pennies, num_pen, remainder);
        change_output = change_result(total_change, num_quar, num_dim, num_nick, num_pen);
        change_output;
        repeat_process = try_again(choice, repeat);
        repeat_process;
    } while (repeat == true);
    return 0;
}
//function requesting user to enter amount of change
int user_request(int &change, int &total_change)
{
    do {
        cout << "Please enter an amount of change between 1 and 99 cents:\n";
        cin >> change;
        total_change = change;
    } while (change < 1 || change > 99);
    return total_change;
}
//function that calculates how many of each type of coin is required for efficient change return
void compute_coins(int coin_value, int &num, int &amount_left)
{
    num /= coin_value;
    amount_left %= coin_value;
}
//function that displays change results
int change_result(int total_change, int num_quar, int num_dim, int num_nick, int num_pen)
{
    cout << total_change << " cents can be given as ";
    if (num_quar > 0)
        cout << num_quar << " quarter(s) ";
    if (num_dim > 0)
        cout << num_dim << " dime(s) ";
    if (num_nick > 0)
        cout << num_nick << " nickel(s) ";
    if (num_pen > 0)
        cout << num_pen << " pennie(s)";
        cout << "." << endl;
    return total_change;
}
//function that repeats entire process upon user request
int try_again(int &choice, bool &repeat)
{
    cout << "To repeat this process press 1 or any other key then enter to exit: ";
        cin >> choice;
        if (choice == 1)
            repeat = true;
    return choice;
}
