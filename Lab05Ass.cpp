// Lab05Ass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"
#include "date.h"
#include "TIME.h"
using namespace std;

//creates a struct with name WindLogType
typedef struct {
    Date d;
    Time t;
    float speed;
} WindLogType;


int main()
{
    //creates Vector class DynArray of WindLogType named windlog.
    Vector<WindLogType> windlog;

    /* Template for reading files
    //reads input file into ifstream
    ifstream infile("MetData-31-3.csv");
    if (!infile) return -1;
    //ifstream to T obj via overload
    infile >> windlog;

    //writes ofstream to output file
    ofstream ofile("routput.txt");
    //R obj to ofstream
    ofile << R;
    */

}

