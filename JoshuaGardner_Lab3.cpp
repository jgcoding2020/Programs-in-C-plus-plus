/*
Lab 3: Practicing sorting algorithms and searching arrays
Author: Joshua Gardner & COP 3014
Date: 12/2/2020
*/

#include <iostream>

const int SIZE = 15; //defined a constant value
//#define SIZE 5    constant macro

// function declarations
int get_min_index (int x [], int begin_index);
void swap_values (int& value1, int& value2);
void selection_sort (int x[]);    //sorting algorithm that sorts in ascending order
void bubble_sort (int x[]);
using namespace std;

int main()
{
    int apples [SIZE] = {9, 2, 45, -4, 5};
    //test for debugging purposes
    //int min_index = get_min_index (apples, 0, SIZE);
    //cout << min_index << endl;

    //selection_sort(apples, SIZE);
    bubble_sort (apples);

    for (int x: apples)
        cout << x << endl;


    return 0;
}

int get_min_index (int x [], int begin_index)
{
    int min_value = x[begin_index];
    int min_index = begin_index;

    for (int i = begin_index+1; i < SIZE; i++)
        if (x[i] < min_value)
        {
            min_value = x[i];
            min_index = i;
        }
    return min_index;
}

void swap_values (int& value1, int& value2)
{
    int temp = value1;

    value1 = value2;

    value2 = temp;
}

void selection_sort (int x[])
{
    for (int i = 0; i < SIZE; i++)
    {
        int min_index = get_min_index (x, i);

        if (i != min_index)
            swap_values (x[i], x[min_index]);
    }
}

void bubble_sort (int x[])
{
    for (int i = SIZE - 1; i > 0; i--)  //shrinking the array search
        for (int j = 0; j < i; j++)
    {
        if (x[j] > x[j+1])
            swap_values (x[j], x[j+1]);  //bubble the largest number to the end
    }
}
