//It's for unit testing.

#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
#include "date.h"
#include "TIME.h"
using namespace std;
int main()
{
    //unit testing for date class
    cout << "Unit testing for the date class:" << endl;
    Date theDate = Date(22, "Dec", 1993);
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
    dateList.SetVector(Date(23, "Jan", 1970), count++);
    dateList.SetVector(Date(03, "Feb", 1960), count++);
    dateList.SetVector(Date(05, "Mar", 1969), count++);
    dateList.SetVector(Date(06, "Apr", 1943), count++);
    dateList.SetVector(Date(31, "May", 1855), count++);
    dateList.SetVector(Date(14, "Jun", 1977), count++);
    
    cout << "Count: " << count << endl;

    //retrieving from the dynamic array
    for (int i = 0; i < count; i++)
    {
        Date tempDate;
        tempDate = dateList.GetVector(i);
        cout << tempDate.GetDay() << "/" << tempDate.GetMonth() << "/" << tempDate.GetYear() << endl;
    }





}