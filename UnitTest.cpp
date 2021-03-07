//It's for unit testing.

#include <iostream>
#include "vector.h"
#include "date.h"
using namespace std;
int main()
{
    //unit testing for date class
    Date theDate = Date(22, "Dec", 1993);
    cout << theDate.GetDay() << "/" << theDate.GetMonth() << "/" << theDate.GetYear() << endl;
    cout << "Size of date obj: " <<  sizeof(theDate) << endl;
    //unit testing for vector class
    

    //making a dynamic array to contain Date objects
    Vector <Date> dateList;
    cout << "Size of datelist: " << sizeof(dateList) << endl;


    //filling some Date objects in
    int count = 0;
    dateList.SetVector(Date(23, "Jan", 1970), 0);
    count++;
    dateList.SetVector(Date(03, "Feb", 1960), 1);
    count++;
    dateList.SetVector(Date(05, "Mar", 1969), 2);
    count++;
    //retrieving from the dynamic array
    for (int i = 0; i < count; i++)
    {
        Date tempDate;
        tempDate = dateList.GetVector(i);
        cout << tempDate.GetDay() << "/" << tempDate.GetMonth() << "/" << tempDate.GetYear() << endl;
    }









}