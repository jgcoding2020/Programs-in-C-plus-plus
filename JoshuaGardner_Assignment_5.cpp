/* Name: Joshua Gardner
Purpose: using iofstream class objects to read/write to/from txt files to generate random numbers and calculate avg/std dev. */

#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>

using namespace std;
// function that generates N random (random) numbers and stores them to a txt file
void Random_Input(ofstream& outfile);
// function that reads the values from a text file and stores them in a neater fashion
void makeneat(ifstream& messy_file, ofstream& neat_file, int& file_size);
// function that appends the "Results" file to include the avg of N random numbers
double averages(ifstream& infile, ofstream& outfile, int file_size);
// function that appends the "Results" file to include the standard deviation of N random numbers
void std_dev(ifstream& infile, ofstream& outfile, double average, int file_size);

int main()
{
    // function variables and random time seed
    srand(time(0));
    double call_average, average;
    int file_size;
    // iofstream class object declarations
    ifstream infile;
    ofstream outfile;
    // .operator assigns ofstream to initial.txt file
    outfile.open("initial.txt");
    // ofstream fail notification and program termination
    if (outfile.fail())
    {
        cout << "Could not open outfile." << endl;
        exit(1);
    }
    // functiona call to generate random numbers and store them in initial.txt file
    Random_Input(outfile);
    //ofstream file closed
    outfile.close();
    // iofstreams opened
    infile.open("initial.txt");
    outfile.open("Results.txt");
    // iofstreams failure notifications and program termination
    if (outfile.fail())
    {
        cout << "Could not open outfile." << endl;
        exit(1);
    }

    if (infile.fail())
    {
        cout << "Could not open infile." << endl;
        exit(1);
    }
    // sets visual spacing etc of number display in ofstreams/ostream
    outfile.setf(ios::showpoint);
    outfile.setf(ios::showpos);
    outfile.setf(ios::right);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.setf(ios::right);
    cout.precision(6);
    // function call read the values from initial.text file/ stores them in Results.txt file in a neater/ modified fashion
    makeneat(infile, outfile, file_size);
    // iofstreams closed
    outfile.close();
    infile.close();
    //iofstreams opened
    infile.open("initial.txt");
    outfile.open("Results.txt", ios::app);
    // iofstreams failure notifications
     if (infile.fail())
    {
        cout << "Could not open infile." << endl;
        exit(1);
    }

     if (outfile.fail())
    {
        cout << "Could not open outfile." << endl;
        exit(1);
    }
    // function that appends the "Results" file to include the avg of N random numbers
    call_average = averages(infile, outfile, file_size);
    call_average;
    // assigns call_average results to main scope variable average
    average = call_average;
    // iofstream files closed
    infile.close();
    outfile.close();
    //iofstream files opened
    infile.open("initial.txt");
    outfile.open("Results.txt", ios::app);
    // iofstream failure notifications
     if (infile.fail())
    {
        cout << "Could not open infile." << endl;
        exit(1);
    }

     if (outfile.fail())
    {
        cout << "Could not open outfile." << endl;
        exit(1);
    }
    // function call that appends the "Results" file to include the standard deviation of N random numbers
    std_dev(infile, outfile, average, file_size);

    infile.close();
    outfile.close();

    return 0;
}
// function that generates N random (random) numbers and stores them to a txt file
void Random_Input(ofstream& rand_outfile)
{
    rand_outfile.setf(ios::fixed);
    rand_outfile.precision(6);
    // variable r is set to randomly generate 101 - 999 numbers
    int i, r = (rand() % 898) +102;
    double ran_nums;
    for (i = 1; i <= r; i++)
    {
        ran_nums = (((rand() % 5000) + 0.012345) * 1.012345) / 100;
        if (ran_nums > 49.999999)
        rand_outfile << 49.999999 << endl;
        else
        rand_outfile << ran_nums << endl;
    }
}
// function that reads the values from a text file and stores them in a neater fashion
void makeneat(ifstream& messy_file, ofstream& neat_file, int& file_size)
{
    double next;
    file_size = 0;

    while (messy_file >> next)
    {
        neat_file << setw(10) << next << endl;
        cout << setw(10) << next << endl;
        file_size++;
    }
}
// function that appends the "Results" file to include the avg of N random numbers
double averages(ifstream& infile, ofstream& outfile, int file_size)
{
    double total = 0, average, next;

    while (infile >> next)
    {
        total += next;
    }
    average = total/(file_size);
    outfile << endl << setw(10) << average << " is the average" << ".";
    cout << endl << setw(10) << average << " is the average" << ".";
    return average;
}
// function that appends the "Results" file to include the standard deviation of N random numbers
void std_dev(ifstream& infile, ofstream& outfile, double average, int file_size)
{
    double next, total_squ = 0, squ_avg, std_dev;

    while (infile >> next)
    {
        total_squ += pow((next-average), 2);
    }
    squ_avg = total_squ/file_size;
    std_dev = sqrt(squ_avg);

    cout << endl << setw(10) << std_dev << " is the standard deviation" << "." << endl;
    outfile << endl << setw(10) << std_dev << " is standard deviation" << "." << endl;
}
