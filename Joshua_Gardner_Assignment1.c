/* Content: comprehension of print function, performing calculations, and use of scanf
Author: Joshua Gardner
Date: 06/01/2020 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    // 1. printf name arrangements

    printf("\nJoshua Gardner\n"); // prints first and last name on one line

    printf("\nJoshua\n\nGardner\n"); // prints first and last name on two separate lines with a line of space inbetween

    printf("\nJoshua "); // prints first name

    printf("Gardner\n"); // prints last name next to first name from previous printf

    // 2. Toes calculations

    int toes = 10; // identifies int variable toes and sets its value to 10

    int toesx2 = toes * 2; // identifies toesx2 as a variable representing the value of toes x 2

    int toessquared = toes * toes; // identifies toessquared as a variable representing the value of toes squared

    printf("\n\n%d = toes.\n\n%d = toes x 2.\n\n%d = toes ^ 2.\n\n", toes, toesx2, toessquared);

    // 3. Fahrenheit to celsius calculation

    int fahrenheit; // temperature in degrees fahrenheit

    double celsius; // identifies double variable celsius

    printf("\nHello user, please enter the degrees in fahrenheit to be converted to celsius:\n"); // prints message to user

    scanf("%d", &fahrenheit); // prompts user to enter temperature in fahrenheit

    celsius = (fahrenheit - 32) * (5 / 9); // converts temperature in fahrenheit to celsius

    printf("\nOk, the temperature is %.2f degrees celsius.\n", celsius); // prints converted temperature in celsius

    /* 4. program that estimates the temperature in a freezer (in °C) given the elapsed time (hours)
    since a power failure. Assume this temperature ( T ) is given by*/

    double hrs;
    double min;

    printf("\nPlease enter the number of hours and then the number of minutes your freezer has been without power: \n");
    scanf("%lf%lf", &hrs, &min);

    double t;
    t = hrs + min/60;

    double T;
    T = (4 * t * t)/(t + 2) - 20;

    printf("The current temperature of your freezer is %.0f degrees celsius.\n", T);

    return 0;
}
