/* Content: Creating void functions with loops, conditional statements, and arrays
Author: Joshua Gardner
Date: 07/18/2020 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes

void speed (void); // Q1 function prototype

void compare (void); // Q2 function prototype

void num_squ_cube (void); // Q3 function prototype

void numbers (void); // Q4 function prototype

int main()
{
    // Q1

    speed(); // Q1 function call

    // Q2

    compare(); // Q2 function call

    // Q3

    num_squ_cube();// Q3 function call

    // Q4

    numbers(); // Q4 function call

    return 0;
}

// Q1 function that uses a while loop and switch statement to incrementally count to 400 million

void speed (void) // function declaration
{
    int count = 1; // identifies int type variable count and assigns its value to 1

    while (count <= 400000000) { // while loop that continues until count value reaches 400 million
        switch (count) { // switch statement that checks the value of count every loop
        case 100000000: // condition when count = 100 million perform the following up until break line
            printf("%d execution time approximately .2 sec\n", count); // when case condition is met: displays the value of count
            count++; // postfix incremental increase to value of count by 1 when case condition is met
            break; // ends the switch statement evaluation if case condition is met
        case 200000000: // condition when count = 200 million perform the following up until break line
            printf("%d execution time approximately .4 sec\n", count); // when case condition is met: displays the value of count
            count++; // postfix incremental increase to value of count by 1 when condition is met
            break; // ends the switch statement evaluation if case condition is met
        case 300000000: // condition when count = 300 million perform the following up until break line
            printf("%d execution time approximately .6 sec\n", count); // when case condition is met: displays the value of count
            count++; // postfix incremental increase to value of count by 1 when condition is met
            break; // ends the switch statement evaluation if case condition is met
        case 400000000: // condition when count = 100 million perform the following up until break line
            printf("%d execution time approximately .8 sec\n", count); // when case condition is met: displays the value of count
            count++; // postfix incremental increase to value of count by 1 when case condition is met
            break; // ends the switch statement evaluation if case condition is met
        default: // defaults here when no case conditions are met
            count++; // postfix incremental increase to value of count by 1 when case condition is met
        }
    }
}

// Q2 function that uses a loop/ if statement/ user entry to compare 2 calculated values based on user entered value

void compare (void) // function declaration
{
    int n, n1 = 0, n2, n3, count; // identifies int variables and assigns n1 = 0

    printf("\nPlease enter an integer: \n"); // displays a request to user
    scanf("%d", &n); // assigns user entered value to variable n

    for (count = 1; count <= n; count++) { // for loop continuity conditions
        n1 = count + n1; // variable n1 assignment
            do { // do loop
                n2 = n1 + (n - 1) + n; // do loop task
                n3 = (n * (n + 1))/2; // do loop task
            } while (count == n + 1); // while true condition to execute do loop tasks
    }

    if (n2 == n3) // if condition
        printf("%d and %d are the same.\n", n2, n3); // task to perform when if condition is true
    else
        printf("%d and %d are different.\n", n2, n3); // task to perform when if condition is false

    // displays explanation for value of n statement to screen
    printf("All values for n are the same each time the code is run, because n always = the user entered value.\n");
}

// Q3 loop function that creates a table based on user entered valaues

void num_squ_cube (void) // function declaration
{
    int count, count2, lower, upper, square, cube; // identifies int variables
    printf("\nPlease enter table lower limit: integer between 0 and 1290: \n"); // displays user request statement
    scanf("%d", &lower); // stores user entry in variable lower
    printf("Please enter table upper limit: an integer <= 1290 and > lower limit choice: \n"); // displays user request statement
    scanf("%d", &upper); // stores user entry into variable upper
    int table_calc[1291][3]; // identifies int array

    for (count = lower; count <= upper; count++) { // for loop condition
        square = pow(count, 2); // square value calculation assignment
        cube = pow(count, 3); // cube value calculation assignment
        table_calc[count][0] = count; // array index assignment
        table_calc[count][1] = square; // array index assignemnt
        table_calc[count][2] = cube; // array index assignment
        for (count2 = 0; count2 < 3; count2++) { // nested for loop condition
            printf("%20d", table_calc[count][count2]); // displays to screen array values in rows and columns
        }
        printf("\n"); // provides line spacing
    }
}

// Q4 function that uses nested loops to display a specific organization of numbers

void numbers (void) // function declaration
{
    int count, count1, count2, count3, count4, count5, count6, count7, count8, count9, count10; // identifies int variables

    // nested for loops that display the loop counts in a triangular fashion

    for (count = 0; count < 1; count++) {
        printf("\n%3d\n", count);
        for (count1 = 0; count1 < 2; count1++) {
            printf("%3d", count1);
        }
        printf("\n");
            for (count2 = 0; count2 < 3; count2++) {
                printf("%3d", count2);
            }
            printf("\n");
                for (count3 = 0; count3 < 4; count3++) {
                printf("%3d", count3);
                }
                printf("\n");
                    for (count4 = 0; count4 < 5; count4++) {
                    printf("%3d", count4);
                    }
                    printf("\n");
                        for (count5 = 0; count5 < 6; count5++) {
                        printf("%3d", count5);
                        }
                        printf("\n");
                            for (count6 = 0; count6 < 5; count6++) {
                            printf("%3d", count6);
                            }
                            printf("\n");
                                for (count7 = 0; count7 < 4; count7++) {
                                printf("%3d", count7);
                                }
                                printf("\n");
                                    for (count8 = 0; count8 < 3; count8++) {
                                    printf("%3d", count8);
                                    }
                                    printf("\n");
                                        for (count9 = 0; count9 < 2; count9++) {
                                        printf("%3d", count9);
                                        }
                                        printf("\n");
                                            for (count10 = 0; count10 < 1; count10++) {
                                            printf("%3d", count10);
                                            }
                                            printf("\n");
    }
}

