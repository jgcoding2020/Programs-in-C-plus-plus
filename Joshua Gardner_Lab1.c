/* THE BASIC SYNTAX OF A C PROGRAM, DECLARE AND INITIALIZE
APPROPRIATE VARIABLES, WRITE SIMPLE ARITHMATIC EXPRESSIONS.
Author: Joshua Gardner
Assignment: Lab 1
Date: 06/01/2020 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RATE 1.50

int main(){

    int day = 20, month = 1, dumpster1; // identifies int type variables and day/month values
    double dumpster2; // identifies double type variable dumpster2
    char initial = 'G'; // identifies char type variable initial with value G

    month = month + 12; // 1 + 12 = 13 increases value of month by 12
    day = day + 30; // 20 + 30 = 50 increases the value of day by 30

    dumpster1 = day / month; // 50 / 13 = 3 divides birthday by month
    dumpster2 = day % month; // 50 % 13 = 11 remainder of dividing day by month

    dumpster1 = dumpster1 / RATE; // 3 / 1.50 = 2 divides dumpster1 by RATE
    dumpster2 = dumpster2 * RATE; // 11 * 1.50 = 16.500000 multiplies dumpster2 by RATE

    printf("%d \n", dumpster1);
    printf("%f", dumpster2);

    return 0;
}
