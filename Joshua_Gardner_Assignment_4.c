/* COP2220 001 10675
Purpose: Use of functions, pointers, arrays, loops, etc
Author: Joshua Gardner z15117842
Assignment: Assignment 4
Date: 07/2/2020 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
// constant macro
#define SIZE 24
// function prototypes
double sum_n_avg(double one, double two, double three); // Q1 double function prototype
// main function
char word_eval(char *word,int size); // Q2 function prototype

int main()
{
    // Question 1
    double n1, *n1Ptr, n2, *n2Ptr, n3, *n3Ptr, math_func; //identifies double variables/ pointers
    int numbers, digits, noDigits;
    printf("Question 1:\n\n"); // displays statement to screen
    printf("Please enter 3 numbers:\n"); // displays statement to screen
    scanf("%lf%lf%lf", &n1, &n2, &n3); // allows user to enter 3 numbers
    n1Ptr = &n1; // pointer to n1
    n2Ptr = &n2; // pointer to n2
    n3Ptr = &n3; // pointer to n3
    math_func = sum_n_avg(*n1Ptr, *n2Ptr, *n3Ptr); // sum_n_avg function call
    math_func;
    // End question 1 main

    char word_input[SIZE], word_eval_func; // identifies char variable and array
    int a, z, A, Z, keyword, success, noSuccess; // identifies int variables
    printf("Question 2:\n"); // displays statement to screen
    printf("\nPlease enter a word less then 25 characters long starting with a hashtag:\n"); // displays statement to screen
    do { // do while loop
        scanf("%s", word_input); // assigns user input string to word_input array
        if (isalpha(word_input[1]) && word_input[0] == '#') // checks conditions the first and second elements of the word_input array
            keyword = success; // assigns variable success to variable keyword when if conditions are true
        else { // when if conditions are false
            printf("You must enter a word that starts with a hashtag. Try again:\n"); // displays statement to screen
            keyword = noSuccess; // assigns variable noSuccess to keyword when if conditions are false
        } // end compound else
    } while (keyword != success); // while condition set to loop through do tasks until keyword == success
    word_eval_func = word_eval(word_input, SIZE); // word_eval function call
    word_eval_func;
    return 0;
}
// Question 1 function
double sum_n_avg(double one, double two, double three) // double function declaration/ input/ output arguments/ types
{
    double sum_of_3, avg_of_3, *sumPtr, *avgPtr; // identifies local double variables/ pointers
    sum_of_3 = one + two + three; // assigns sum_of_3 the sum of 3 input numbers as its value
    avg_of_3 = sum_of_3/3; // assigns avg_of_3 the average of 3 input numbers as its value
    sumPtr = &sum_of_3; // pointer to sum_of_3
    avgPtr = &avg_of_3; // pointer to avg_of_3
    // return displays the sum and average of 3 input numbers through the use of pointers
    return printf("The sum: %f\nThe average: %f\n", *sumPtr, *avgPtr);
} // End question 1 function
// Question 2 function
char word_eval(char *word,int size) // word_eval function declaration
{
    if (islower(word[1])) { // checks if the string arrays 2nd element is lower case
        word[1] = toupper(word[1]); // if array element 1 is lower case it is changed to upper case
        return printf("%s starts with the letter %c\n", word, word[1]); // displays statement with string
    } // end compound if
    else
        return printf("%s starts with the letter %c\n", word, word[1]); // displays statement to screen when if condition is false
}
