// Lab05Ass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"
#include "date.h"

int main()
{
    Date theDate = Date(22, "Dec", 1993);
    theDate.GetDay();
    theDate.GetMonth();
    theDate.GetYear();
}

