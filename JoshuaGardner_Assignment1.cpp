/* Name: Joshua Gardner
Date: 9/06/20
Content: Using I/O, int variable declarations,
variable value assignments and calculations. */
#include <iostream>

using namespace std;

int main()
{
    int quarters, dimes, nickels, total_change; // a,c) declares int type variables
    cout <<"Please enter the number of quarters:\n"; // b) displays message to user
    cin >> quarters; // b) allows user to input a value for variable quarters
    cout <<"Please enter the number of dimes:\n"; // b) displays message to user
    cin >> dimes; // b) allows user to input a value for variable dimes
    cout <<"Please enter the number of nickels:\n"; // b) displays message to user
    cin >> nickels; // b) allows user to input a value for variable nickels

    total_change = (quarters*25)+(dimes*10)+(nickels*5); // c) assigns variable total_change what coins are worth
    // d) The algorithm: Step 1: Problem solving: established variable I/O required, and how the results should be arranged
    // d) The algorithm: Step 2: Implementing: Wrote the code, tested the code, results were correct
    cout <<"The coins are worth " << total_change << " cents.\n"; // e) displays calculated results to user

    return 0;
}
