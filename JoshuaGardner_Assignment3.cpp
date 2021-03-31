/*
NAME: Joshua Gardner Z15117842
COURSE: COP 3014-003
ASSGNMENT: Assignment 3
PURPOSE: Displaying prime numbers in between 3 and user entered value
DATE: 10/01/2020
*/

#include <iostream>

using namespace std;

int main()
{
    // variable declarations/ initializations
    int number, loop_count = 3, prime_number, prime_number2, nested_count, total_primes = 0;
    bool prime;

    // loop requesting user to enter a number greater then 2
    do {
        cout << "Please enter a number greater then 2: " << endl;
        cin >> number;
    } while (number < 3);

    // loop/ nested loop that determines which numbers are prime in between 3 and the user entered number
    while (loop_count <= number)
    {
        prime = true;
        for (nested_count = 2; nested_count <= (loop_count - 1); nested_count++)
        {
            if ((loop_count % nested_count) == 0)
                prime = false;
        }
    // displays prime numbers to screen
        if (prime == true)
        {
            cout << loop_count << " is a prime number." << endl;
            total_primes++;
        }
        loop_count++;
    }
    // displays total number of primes between 2 and user entered value
    cout << "There are " << total_primes << " prime numbers between 2 and " << number << "." << endl;
    return 0;
}
