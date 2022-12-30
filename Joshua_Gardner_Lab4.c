/* Author: Joshua Gardner
Content: Use of functions along with for loops, while loops, and arrays
Date: 7/11/2020 */

#include <stdio.h>
#include <stdlib.h>

// constant macro

#define ROWS 7
#define COLUMNS 2
//#define SEVEN 7 //constant macro for Q2_2 second option

/* I saw multiple ways to accomplish Q2. I wasn't sure if it mattered which method I used.
If you want to test my second method for Q2, the following parts will need to be removed from comments:
constant macro, function prototype, function call, and function declaration/ body */

// function prototypes

void function_Q1 (void);

void function_Q2 (void);

//void function_Q2_2(void);

void function_Q3 (void);

int main()
{
    function_Q1 (); // Q1 function call

    function_Q2 (); // Q2 function call for 2 dimensional array

    //function_Q2_2 (); // Q2 function call for 1 dimensional array

    function_Q3 (); // Q3 function call

    return 0;
}

// Q1 function

void function_Q1 (void)
{
    int i = 1; // identifies i as type int variable and assigns value 1 to i

    double n; // identifies n as type double variable

    // while loop that continuously divides n by i while incrementally increasing the value of i by 1 until value of i = 30

    printf("\nWatch out! Here come a bunch of fractions!\n\n"); // displays statement to screen
    while (i < 30) // loop condition: continues while i <= 30
    {
        n = (double)1/i; // assigns value 1/i to n
        printf("n = 1/%d or %f\n\n", i, n); // displays to screen the new value of n every loop
        i++; // postfix operator increases value of i by 1 at the end of every loop
    }

    printf("That's all, folks!\n\n"); // displays statement to screen
}

// Q2 function using multidimensional array method

void function_Q2 (void)
{
    // identifies chart[][] as a 2 dimensional type int array
    int chart[ROWS][COLUMNS] = {{0, 1}, {1, 2}, {2, 4}, {3, 8}, {4, 16}, {5, 32}, {6, 64}};
    int r, c; // identifies int type variables r and c

    for (r = 0; r <= 6; r++) // for loop that assigns value 0 to r and increases r value by 1 each loop up to r = 6
    {
        for (c = 0; c <= 1; c++) // nested for loop that assigns c value 0 and increases its value by 1 each loop up to c = 1
        {
        printf("%5d", chart[r][c]); // displays each row in the chart[][] array as the loops occur
        }
    printf("\n"); // establishes new display line after each nested loop completes
    }
}

// Q2 function using a 1 dimensional array method

/*
void function_Q2_2 (void)
{
    int s; // identifies s as variable type int
    int single[SEVEN] = {1, 2, 4, 8, 16, 32, 64}; // identifies single[] as int type array and assigns 7 values to its 7 indices

    printf("\n"); // line space
    for (s = 0; s <= 6; s++) // for loop that assigns value 0 to s and sets the condition to continue the loop until s <= 6
    printf( "%5d%5d\n", s, single[s]); // displays value of s and single[s] to the screen
}
*/

// Q3 function

void function_Q3 (void)
{
    int count, next_num, sum = 0; // identifies int type variables count, next_num, sum, and assigns value 0 to sum
    count = 0; // assigns value 0 to variable count

    printf("\nPlease enter 5 numbers to be added together creating a sum: \n\n"); // displays a request to user to enter a number to add
    while (count < 5) // loop that continues under the condition that count < 5
    {
    printf("Next number> ");
    scanf("%d", &next_num); // assigns the user entry value to variable next_num
    sum += next_num; // assigns variable sum the value of sum + next_num
    count++; // postfix operator increases value of count by 1
    }
    printf("\n%d numbers were added; \n", count); // displays the value of count along with a statement to user
    printf("\nTheir sum is: %d\n", sum); // displays the value of sum along with a statement to user
}
