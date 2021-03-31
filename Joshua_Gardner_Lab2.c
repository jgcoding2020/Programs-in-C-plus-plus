/* COP2220 001 10675
OBJECTIVE: Writing functions with input/output arguments as well as void functions.
Author: Joshua Gardner z15117842
Assignment: Lab2
Date: 06/13/2020 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes

double avg (int x, int y, int z);

void pyramid (double value);

int main()
{
    // identifies variables x, y, z as int type
    int x, y, z;

    // requests user to enter 3 integers to calculate an average on
    printf("\nHello user, please enter 3 integers you would like to have an average calculated on: \n");

    // takes users 3 integers and places their values on variables x, y, and z
    scanf("%d%d%d", &x, &y, &z);

    // prints the 3 integers and their average to the screen
    printf("\nThe average of numbers %d, %d, and %d = %.6f\n", x, y, z, avg( x, y, z));

    // call and prints pyramid function with avg function inside
    pyramid (avg( x, y, z));

    return 0;
}

    // function that calculates the average of 3 int variables
double avg (int x, int y, int z)
{
    double average;
    average = (double)((x + y + z)/3.0); // identifies variable average assignment calculation type casting values as double
    return(average);

}

    // function that surrounds the double value with the shape of a triangle
void pyramid (double value)
{
    printf("          *           \n");
    printf("        *   *         \n");
    printf("                      \n");
    printf("     *         *      \n");
    printf("       %.6f           \n", value);
    printf("  *                *  \n");
    printf("* ** ** ** ** ** ** **\n");
}

