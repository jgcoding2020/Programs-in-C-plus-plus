/* Content: Conditional statements and use of if/if else control structures.
Author: Joshua Gardner
Date: 06/20/2020 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// functions prototypes

void Q1a(int age);

void Q1b(double deduct, double balance);

double value(double num1, double num2);

int main()
{
    int age; // identifies age as variable type int

    printf("\nPlease enter your age: "); // requests user to enter his/her age
    scanf("%d", &age); // takes user entry and applies the value to int age

    Q1a(age); // calls to Q1a function

    double deduct; // identifies deduct as variable type double
    double balance; // identifies balance as variable type double

    balance = 65000; // sets value to variable balance as 65000

    printf("\n\nPlease enter the amount you would like to withdraw: \n"); // requests user to enter amount to withdraw
    scanf("%lf", &deduct); // sets deduct value entered by user

    Q1b(deduct, balance); // calls to function Q1b(deduct, balance)

    double num1; // identifies num1 as variable type double
    double num2; // identifies num2 as variable type double

    printf("\nEnter any 2 numbers to calculate their differences: \n"); // requests user to enter 2 numbers
    scanf("%lf%lf", &num1, &num2); // sets values for num1 and num2 based on user entry

    //double abs_value; // identifies abs_value as variable type double
    //abs_value = value(num1, num2); // assigns variable abs_value as function call to value function
    printf("\n\nThe absolute value is: %.2f\n", value(num1, num2)); // prints results of value function

    return 0;
}

void Q1a(int age) // Q1a function evaluates if user entry "age" is >= 65 or < 65 and prints result when called in main
{
    if (age >= 65)
        printf("\nAge is greater than or equal to 65\n");
    else
        printf("\nAge is less than 65\n");
}

void Q1b(double deduct, double balance) // function that evaluates deduction amount and prints results according to calculation outcome
{
    balance = balance - deduct; // sets balance equal to balance - deduct

    if (deduct < balance) // evaluates whether there are enough funds to withdrawal deduction amount and prints results
        printf("\n\nDeduction = %.2f \nNew balance = %.2f \n\nFinal balance = %.2f\n", deduct, balance, balance);
    else
        printf("\nDeduction of %.2f refused. \n\nWould overdraw account.\n\n", deduct);

}

// function that evaluates the difference between num1 and num2 returning the difference that is an absolute value
double value(double num1, double num2)
{
    double x;
    double y;
    x = num1 - num2;
    y = num2 - num1;

    if (x == fabs(x))
        return ("%f", x);
    else
        return ("%f", y);
}
