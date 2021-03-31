/* COP2220 001 10675
Purpose: Writing functions that utilize user input values
to display messages and calculated results
Author: Joshua Gardner z15117842
Assignment: Assignment 2
Date: 07/03/2020 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// constant macros

#define GRAMS_MOLECULE 3 * 10e-23
#define GRAMS_QUART 950

// Function prototypes

void lighting (void);

double BMI_calculator (double weight, double height);

void plane_point (double x, double y);

double quarts_molecules (double quarts);

int main()
{

    // 1. Calls to void function lighting

    lighting();

    // 2. BMI_calculator function variables, function call, and I/O statements

    double height;
    double inches;
    double weight;

    printf("\nPlease enter your height in inches: \n\n");
    scanf("\n%lf", &inches);

    height = inches;

    printf("\nPlease enter your weight in lbs: \n\n");
    scanf("\n%lf", &weight);

    double weight_status;
    weight_status = BMI_calculator(weight, height);
    printf("%.1f\n", weight_status);

    // 3. plane_point function variables, function call, and I/O statements

    double x;
    double y;

    printf("\nPlease enter the x and then y coordinates of a point in a Cartesian plane: \n\n");
    scanf("\n%lf%lf", &x, &y);

    plane_point(x, y);

    // 4. quarts_molecules function variables, function call, and I/O statements

    double quarts;

    printf("\nPlease enter a volume of quarts of water: \n\n");
    scanf("\n%lf", &quarts);

    double number_molecules;
    number_molecules = quarts_molecules (quarts);
    printf("\n%.2f quarts of water contains:\n\n%e molecules of water.\n", quarts, number_molecules);

    return 0;
}

// 1. Switch function that assigns a value to lumens depending on watts user input value

void lighting (void)
{
    int lumens;
    int watts;

    printf("\nPlease enter a wattage amount: \n\n");
    scanf("%d", &watts);

    switch(watts)
    {
    case 15:
        lumens = 125;
        printf("\nThe brightness level is %d lumens.\n", lumens);
        break;
    case 25:
        lumens = 215;
        printf("\nThe brightness level is %d lumens.\n", lumens);
        break;
    case 40:
        lumens = 500;
        printf("\nThe brightness level is %d lumens.\n", lumens);
        break;
    case 60:
        lumens = 880;
        printf("\nThe brightness level is %d lumens.\n", lumens);
        break;
    case 75:
        lumens = 1000;
        printf("\nThe brightness level is %d lumens.\n", lumens);
        break;
    case 100:
        lumens = 1675;
        printf("\nThe brightness level is %d lumens.\n", lumens);
        break;
    default:
        lumens = -1;
        printf("\nThe brightness level is %d lumens.\n", lumens);
    }
}

// 2. function that calculates/ returns BMI and USCDC weight class status based on user entered values

double BMI_calculator (double weight, double height)
{

    double BMI;

    BMI = (703 * weight) / (pow(height, 2));

    if (BMI < 18.5)
    {
        printf("\nAccording to the United States Center for Disease and Control,\n\nyour status is: Underweight\n\nYour BMI is: ");
        return BMI;
    }
    else if (BMI >= 18.5 && BMI < 25.0)
    {
        printf("\nAccording to the United States Center for Disease and Control,\n\nyour status is: Normal\n\nYour BMI is: ");
        return BMI;
    }
    else if (BMI >= 25.0 && BMI <= 30.0)
    {
        printf("\nAccording to the United States Center for Disease and Control,\n\nyour status is: Overweight\n\nYour BMI is: ");
        return BMI;
    }
    else
    {
        printf("\nAccording to the United States Center for Disease and Control,\n\nyour status is: Obese\n\nYour BMI is: ");
        return BMI;
    }
}

// 3. function that displays where a user entered point is located on the Cartesian plane

void plane_point (double x, double y)
{
    if (x > 0 && y > 0)
        printf("\n(%.1f, %.1f) is in quadrant I\n", x, y);
    else if (x < 0 && y >0)
        printf("\n(%.1f, %.1f) is in quadrant II\n", x, y);
    else if (x < 0 && y < 0)
        printf("\n(%.1f, %.1f) is in quadrant III\n", x, y);
    else if (x > 0 && y < 0)
        printf("\n(%.1f, %.1f) is in quadrant IV\n", x, y);
    else if (x == 0 && y != 0)
        printf("\n(%.1f, %.1f) is on the y axis\n", x, y);
    else if (x == 0 && y != 0)
        printf("\n(%.1f, %.1f) is on the x axis\n", x, y);
    else
        printf("\n(%.1f, %.1f) is on the origin\n", x, y);
}

// 4. function that calculates and returns in E form how many molecules of water are in the user entered quarts of water

double quarts_molecules (double quarts)
{
    double grams;
    double molecules;

    grams = quarts * GRAMS_QUART;
    molecules = grams/GRAMS_MOLECULE;

    return molecules;
}
