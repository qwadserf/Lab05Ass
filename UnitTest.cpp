//It's for unit testing.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include "vector.h"
#include "date.h"
#include "TIME.h"
using namespace std;

//creates a struct with name WindLogType
typedef struct
{
    Date d;
    Time t;
    float speed;
} WindLogType;

//function to print the WindLogType
void PrintWind(WindLogType w);

int main()
{
    //unit testing for date class
    cout << "Unit testing for the date class:" << endl;
    Date theDate = Date(22, 12, 1993);
    cout << theDate.GetDay() << "/" << theDate.GetMonth() << "/" << theDate.GetYear() << endl;

    //unit testing for time class
    cout << endl <<  "Unit testing for the time class:" << endl;
    Time theTime = Time(23, 59);
    cout << theTime.GetHour() << ':' << theTime.GetMin() << endl;


    //unit testing for vector class
    cout << endl << "Unit testing for the vector class:" << endl;
    //making a dynamic array to contain Date objects
    Vector <Date> dateList;


    //filling some Date objects in
    int count = 0;
    //testing SetVector method
    dateList.SetVector(Date(23, 01, 1970), count++);
    dateList.SetVector(Date(03, 02, 1960), count++);
    dateList.SetVector(Date(05, 03, 1969), count++);
    dateList.SetVector(Date(06, 04, 1943), count++);
    dateList.SetVector(Date(31, 05, 1855), count++);
    dateList.SetVector(Date(14, 06, 1977), count++);
    
    cout << "Count: " << count << endl;

    //retrieving from the dynamic array
    for (int i = 0; i < count; i++)
    {
        Date tempDate;
        tempDate = dateList.GetVector(i);
        cout << tempDate.GetDay() << "/" << tempDate.GetMonth() << "/" << tempDate.GetYear() << endl;
    }

    //testing the struct WinLogType.
    cout << endl << "Unit testing for the struct WindLogType:" << endl;
    //declare vector of WindLogType called windlog
    Vector<WindLogType> windlog;
    //assign a new WindLogType some values
    WindLogType oneLog;
    oneLog.d = Date(8, 03, 2021);
    oneLog.t = Time(13, 07);
    oneLog.speed = 6;
    //insert the WindLogType obj into the dynArray
    windlog.SetVector(oneLog, 0);
    //then get it, assign to new WLT obj
    WindLogType newLog = windlog.GetVector(0);
    //Then print the details in the new obj
    cout << '\n' << newLog.d.GetDay() << '/' << newLog.d.GetMonth() << '/' << newLog.d.GetYear() << '\t';
    cout << newLog.t.GetHour() << ":" << setfill('0') << setw(2) << newLog.t.GetMin() <<  '\t';
    cout << newLog.speed << endl;

    //testing file input. 
    cout << endl << "Unit testing for file inputs: " << endl;
    string fileName = "MetData-31-3.csv";
    ifstream inFile(fileName);
    istream& input = inFile;
    int countTwo = 0;
    //columns is the number of columns in the data file.
    const int columns = 18;
    string tempStr;

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
        windlog.SetVector(tempWind, countTwo);
        //keep track of number of data lines. For sample should be 90.
        countTwo++;
    }

    //add unique speeds to windspeeds
    //iterate thru windlog. If match, don't add to windspeeds. 
    //If no match, add the new speed to windspeeds
    Vector<float> windspeeds;
    int windspeedCount = 0;
    for (int i = 0; i < countTwo; i++)
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
    cout << "wind speeds experienced: " << endl;
    for (int i = 0; i < windspeedCount; i++)
    {
        cout << windspeeds.GetVector(i) << '\t';
    }
    cout << endl;

    //testing windlog output, and getting the sum and avg
    float sum = 0.0f;
    float avg = 0.0f;
    for (int i = 0; i < countTwo; i++)
    {
        PrintWind(windlog.GetVector(i));
        sum += windlog.GetVector(i).speed;
    }
    avg = sum / (countTwo + 1);
    cout << fixed << setprecision(2) << "Average wind speed for " << (countTwo + 1) << " entries is " << avg << endl;
    cout << fixed << setprecision(0) << "Average wind speed for " << (countTwo + 1) << " entries is " << round(avg);


} //end main

void PrintWind(WindLogType w)
{
    cout << "Date:  " << setw(2) << setfill('0') << w.d.GetDay() << '/' << setw(2) << w.d.GetMonth() << '/' << w.d.GetYear() << endl;
    cout << "Time:  " << setw(2) << w.t.GetHour() << ":" << setw(2) << w.t.GetMin() << endl;
    cout << "Wind:  " << w.speed << '\n' << endl;
};
