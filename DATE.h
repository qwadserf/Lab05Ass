/**
 *\class Date
 *\brief Date class definition
 *\author Edric
 */


#ifndef DATE_H
#define DATE_H


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

class Date {
public:
    /**
     * @brief default constructor for Date
    */
    Date();

    /**
     * @brief Constructor for date obj
     * @param d - the day
     * @param m - the month
     * @param y - the year
    */
    Date(int d, string m, int y);

    /**
     * @brief get day
     * @return day
    */
    int GetDay() const;

    /**
     * @brief get month
     * @return month
    */
    string GetMonth() const;

    /**
     * @brief get year
     * @return year
    */
    int GetYear() const;
     
    /**
     * @brief sets day
     * @param d - the day
    */
    void SetDay(int d);

    /**
     * @brief sets month
     * @param m - the month
    */
    void SetMonth(string m);

    /**
     * @brief sets year
     * @param y - the year
    */
    void SetYear(int y);


private:
    int day;
    string month;
    int year;
};

/**
 * @brief overloads the << operator, ostream into the Date object.
 * @param output - the ostream
 * @param D - the Date obj
 * @return output
*/
ostream& operator << (ostream& output, const Date& D);

/**
 * @brief overloads the >> operator, istream, into the Date object.
 * @param input - the istream
 * @param D - the Date obj
 * @return input
*/
istream& operator >> (istream& input, Date& D);

#endif