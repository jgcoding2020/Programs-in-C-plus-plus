/* COP2220 001 10675
Purpose: Understanding of functions, arrays, pointers, strings
Author: Joshua Gardner z15117842
Assignment: Lab 5
Date: 07/31/2020 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100 // constant macro
//function prototypes
void Q1(void); // Q1

void Q2(void); // Q2

void Q3(void); // Q4

// main function
int main()
{

    Q1(); // question 1 function call

    Q2(); // question 2 function call

    /* Question 3

    #define SIZE 1 // constant macro for array length

    void zero(double big_nums); // void function prototype******************** a)

    int add1AndSum(int one_small[], size); // int function prototype********** c)

    int main() // main function
    {
    double big_nums; // identifies double variable
    zero(big_nums); // void function call************************************* b)

    int one_small[SIZE] = {5}; // identifies int variable
    int add; // int variable
    add = add1AndSum(one_small, SIZE); // int function call******************* d)
    printf("%d", add); // displays int function results

    return 0;
    }
    End Question 3*/
    printf("\nQuestion 4\n\n");
    Q4();

    return 0;
}
// Question 1 function
void Q1(void) // function declaration
{
    int b[SIZE], i; // identifies int array and variable
    printf("Question 1\n\n"); // displays statement
    printf("The array b consists of these elements:\n"); // displays statement
    for (i = 0; i < SIZE; i++) { // for loop control variable/ condition/ variable increment
    b[i] =+ i; // assigns array elements b[0]-b[99] the values 0-99
    printf("%-5d", b[i]); //displays all array elements
    }
    printf("\n\nThe 2 dimensional array a consists of these elements:\n"); // displays statement
    int a[2][3] = { { 1, 2, 3 }, { 3, 4 } }; // initializes array and assigns its elements/ values
    a[1][2] = 5; // missing element assignment
    int row, column; // identifies int variables

    for (row=0; row < 2; row++) { // for loop control variable/ condition/ variable increment
        for (column=0; column < 3; column++) { // nested for loop control variable/ condition/ variable increment
            printf("%-5d ", a[row][column]); //displays array elements
        }
        printf("\n"); // new line
    }
}
// Question 2
void Q2(void) // void function declaration
{
    int apples[5] = {2,4,6,8,10}; // 2 a) initializes apples array and assigns its element's values
    int *aPtr, i; // 2 b,c) identifies int pointer and variable
    aPtr = apples; // 2 b,c) assigns pointer the value of array apples address
    printf("\nQuestion 2\n"); // displays statement
    printf("\ne) aPtr is pointing to array apples physical address:\n%d.\n", aPtr); // 2 e) displays physical address of apples
    printf("\nc and f) The apples array consists of these elements:\n"); // displays statement
    for (i = 0; i < 5; i++) // 2 c) for loop control variable/ condition/ increment variable
    {
        printf("%-5d", *(aPtr + i)); // 2 f) displays array element values using offset pointer notation
    }
    printf("\n\ng) aPtr + 3 changes the address aPtr is pointing from apples[0] = %d to apples[3] = %d", *aPtr, *(aPtr + 3)); // 2 g) displays explanation of pointer value changing
    aPtr += 1; // adjusts pointer value to apples[4] address
    aPtr -= 4; // adjusts pointer value to apples[0] address
    printf("\n\nh) aPtr is pointing to apples[0] which has a value of %d\n", *aPtr); // h) displays statement of where aPtr is pointing and what its value is
}
// Question 4
void Q4(void) // void function declaration
{
    char goldwyn[40] = "art of it all "; //string array initialization with 40 length consisting of a 14 length string plus null \0
    char samuel[40] = "I read p"; // string initialization with 40 length consisting of a 8 length string plus null \0
    char quote[] = "the way through."; // string initialization with no established length consisting of a 16 length string plus null \0
    strcat(goldwyn, quote); // string concatenation adds quote string onto end of goldwyn string
    strncat(samuel, goldwyn, 9); // string concatenation that adds the first 9 values of the goldwyn string onto the end of the samuel string
    printf("%s\n%s\n", goldwyn, samuel); // displays the goldwyn and samuel strings on separate lines
    printf("%4d%4d%4d\n",strlen(quote),strlen(goldwyn),strlen(samuel)); //displays all 3 string lengths right justified with 4 length
}
