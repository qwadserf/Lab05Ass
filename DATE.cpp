// DATE.CPP - DATE class implementation

#include "DATE.H"

Date::Date()
{
}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

int Date::GetDay() const
{
    return day;
}

int Date::GetMonth() const
{
    return month;
}

int Date::GetYear() const
{
    return year;
}

void Date::SetDay(int d)
{
    day = d;
}

void Date::SetMonth(int m)
{
    month = m;
}

void Date::SetYear(int y)
{
    year = y;
}


ostream& operator << (ostream& output, const Date& D)
{
    output << "  Date:    " << D.GetDay() << '/' << D.GetMonth() << '/' << D.GetYear() << endl;

    return output;
}

istream& operator >> (istream& input, Date& D)
{
    string temp;
    int tempInt;
    //get set for day (int)
    getline(input, temp, '/');
    tempInt = stoi(temp);
    D.SetDay(tempInt);
    //get set for month (int)
    getline(input, temp, '/');
    tempInt = stoi(temp);
    D.SetMonth(tempInt);
    //get set for year (int)
    getline(input, temp, ' ');
    tempInt = stoi(temp);
    D.SetYear(tempInt);

    return input;
}
