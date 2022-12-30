/* Name: Joshua Gardner
Content: Use of a class/ member functions
Date: 11/14/2020 */

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
//class members/variables/function definitions
class LetsCount{
    public:
        void set(int num);
        void increment();
        void decrement();
        int get_counter();
        void output(ostream& outs);
    private:
        int counter = 0;
};
//function that takes integer inputs from user and ofstreams them to a txt file
void user_input(ofstream& outfile);
//function that counts number of integers entered by user
void num_sum(int& num_count);
//function that counts positive and negative integers
void integer_count(LetsCount& positive, LetsCount& negative);

int main()
{
    ofstream outfile;
    outfile.open("integers.txt");

    if (outfile.fail())
    {
        cout << "Could not open outfile.";
        exit(1);
    }
    //function call to receive user input integers
    user_input(outfile);
    outfile.close();
    //function call to calculate quantity of integers entered
    int num_count;
    num_sum(num_count);
    //member function calls to calculate quantity of positive vs negative integers entered
    //and store the counter values in class LetsCount objects (positive and negative)
    LetsCount positive, negative;
    positive.set(0);
    negative.set(num_count);
    integer_count(positive, negative);

    outfile.open("Results.txt");

    //member function calls to display and evaluate class LetsCount objects counter values
    cout << endl << endl << "You entered ";
    outfile << "You entered ";
    positive.output(cout);
    positive.output(outfile);
    cout << " positive numbers, and ";
    outfile << " positive numbers, and ";
    negative.output(cout);
    negative.output(outfile);
    cout << " negative numbers." << endl;
    outfile << " negative numbers." << endl;
    cout << "The sum of these 2 numbers equals the quantity of integers entered." << endl;
    outfile << "The sum of these 2 numbers equals the quantity of integers entered." << endl;

    return 0;
}
//function declaration that takes integer inputs from user and ofstreams them to a txt file
void user_input(ofstream& outfile)
{
    int num;

    do  {
        cout << "Please enter desired integers then press 0 or any other key to exit:";
        cin >> num;
        if (num > 0 || num < 0)
            outfile << num << endl;
    } while (num != 0);
}
//function declaration counts number of integers entered by user
void num_sum(int& num_count)
{
    num_count = 0;
    int next;
    ifstream infile;
    infile.open("integers.txt");

    if (infile.fail())
    {
        cout << "Could not open infile.";
        exit(1);
    }

    while (infile >> next)
    {
        num_count++;
    }
    infile.close();
}
//member function declaration to set value of counter
void LetsCount::set(int num)
{
    counter = num;
}
//function declaration to calculate quantity of positive and negative integers
void integer_count(LetsCount& positive, LetsCount& negative)
{
    int next;
    ifstream infile;
    infile.open("integers.txt");

    if (infile.fail())
    {
        cout << "Could not open infile.";
        exit(1);
    }

    while (infile >> next)
    {
        if (next > 0)
            positive.increment();
        if (next > 0)
            negative.decrement();
    }
    infile.close();
}
//member function declaration that increments counter
void LetsCount::increment()
{
    counter++;
}
//member function declaration that decrements counter
void LetsCount::decrement()
{
    counter--;
}
//member function declaration that returns counter
int LetsCount::get_counter()
{
    return counter;
}
//member function declaration that outputs to screen or file
void LetsCount::output(ostream& outs)
{
    outs << counter;
}
