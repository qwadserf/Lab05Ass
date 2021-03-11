// Lab05Ass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include "vector.h"
#include "DATE.h"
#include "TIME.h"
using namespace std;

//creates a struct with name WindLogType
typedef struct {
    Date d;
    Time t;
    float speed;
} WindLogType;

//function to print the WindLogType
void PrintWind(WindLogType w);

int main()
{
    //creates Vector class DynArray of WindLogType named windlog.
    Vector<WindLogType> windlog;

    //reading the file
    string fileName = "MetData-31-3.csv";
    ifstream inFile(fileName);
    istream& input = inFile;
    int count = 0;
    //columns is the number of columns in the data file.
    const int columns = 18;
    string tempStr;
    float sum = 0.0f;
    float avg = 0.0f;
    Vector<float> windspeeds;
    int windspeedCount = 0;
    bool avgMatch = false;
    

    //gets the first line then discards it, as they are the names of the columns.
    getline(input, tempStr);
    //process each line of the file. 
    while (!inFile.eof())
    {
        //declare temp WindLogType
        WindLogType tempWind;

        //now iterates across the columns and exracts the required columns.
        for (int i = 0; i < columns; i++)
        {
            //to split the date and time values in column 1
            if (i == 0)
            {
                input >> tempWind.d;
                input >> tempWind.t;
            }
            //to get the wind
            else if (i == 10)
            {
                getline(input, tempStr, ',');
                tempWind.speed = stof(tempStr);
            }
            //to get the last column since delimiter is '\n'
            else if (i == (columns - 1))
            {
                getline(input, tempStr);
            }
            //else get based on delimiter ','
            else
            {
                getline(input, tempStr, ',');
            }
        }
        //set the tempWind into the windLog array.
        windlog.SetVector(tempWind, count);
        //keep track of number of data lines.
        count++;
    }

    //prints the windlog details, and adds to sum and calculates average.
    for (int i = 0; i < count; i++)
    {
        //display the date, time, windspeed
        PrintWind(windlog.GetVector(i));
        //add speed to the sum
        sum += windlog.GetVector(i).speed;
    }

    //add unique speeds to windspeeds
    //iterate thru windlog. If match, don't add to windspeeds. 
    //If no match, add the new speed to windspeeds
    for (int i = 0; i < count; i++)
    {
        bool windspeedFound = false;
        float spdToAdd = windlog.GetVector(i).speed;
        for (int j = 0; j < windspeedCount; j++)
        {
            if (windspeeds.GetVector(j) == spdToAdd)
            {
                windspeedFound = true;
                break;
            }
        }
        //if does not exist, add the spd to windspeeds array.
        if (windspeedFound == false)
        {
            windspeeds.SetVector(spdToAdd, windspeedCount);
            windspeedCount++;
        }
    }
    
    avg = sum / (count + 1);
    //print windspeeds logged.
    cout << "Wind speeds logged: ";
    for (int i = 0; i < windspeedCount; i++)
    {
        cout << windspeeds.GetVector(i) << ' ';
    }
    cout << endl;

    //find the avg speed in the windspeeds list. Else, say avg not in list.
    for (int i = 0; i < windspeedCount; i++)
    {
        if (windspeeds.GetVector(i) == round(avg))
        {
            avgMatch = true;
            break;
        }
    }
    if (avgMatch)
    {
        cout << fixed << setprecision(0) << "Average wind speed for " << (count) << " entries is " << round(avg) << " km/h" << endl;
    }
    else
    {
        cout << "The average speed of " << round(avg) << "km/h could not be found across the " << (count) << " entries." << endl;
    }
    

    //search windlog for matching avg wind speed
    //testing the windspeeds array
    //for (int i = 0; i < windspeedCount; i++)
    //{
      //  cout << windspeeds.GetVector(i) << endl;
   //}
}

void PrintWind(WindLogType w)
{
    cout << "Date:  " << setw(2) << setfill('0') << w.d.GetDay() << '/' << setw(2) << w.d.GetMonth() << '/' << w.d.GetYear() << endl;
    cout << "Time:  " << setw(2) << w.t.GetHour() << ":" << setw(2) << w.t.GetMin() << endl;
    cout << "Wind:  " << w.speed << '\n' << endl;
};
