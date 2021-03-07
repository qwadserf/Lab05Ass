/**
 *\class Time
 *\brief Time class definition
 *\author Edric
 */


#ifndef TIME_H
#define TIME_H


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

class Time {
public:
    /**
     * @brief default constructor for Time
    */
    Time();

    /**
     * @brief Overloaded constructor for Time obj
     * @param hour - the hour
     * @param min - the min
    */
    Time(int hour, int min);

    /**
     * @brief get hour
     * @return hour
    */
    int GetHour() const;

    /**
     * @brief get min
     * @return min
    */
    int GetMin() const;

    /**
     * @brief sets hour
     * @param h - the hour
    */
    void SetHour(int h);

    /**
     * @brief sets min
     * @param m - the min
    */
    void SetMin(int m);


private:
    int hour;
    int min;
};

/**
 * @brief overloads the << operator, ostream into the Time object.
 * @param output - the ostream
 * @param T - the Time obj
 * @return output
*/
ostream& operator << (ostream& output, const Time& D);

/**
 * @brief overloads the >> operator, istream, into the Time object.
 * @param input - the istream
 * @param T - the Time obj
 * @return input
*/
istream& operator >> (istream& input, Time& D);

#endif