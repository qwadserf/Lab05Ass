// TIME.CPP - TIME class implementation

#include "TIME.H"

Time::Time()
{
}

Time::Time(int h, int m)
{
    hour = h;
    min = m;
}

int Time::GetHour() const
{
    return hour;
}

int Time::GetMin() const
{
    return min;
}

void Time::SetHour(int h)
{
    hour = h;
}

void Time::SetMin(int m)
{
    min = m;
}

ostream& operator << (ostream& output, const Time& T)
{
    output << "  Time:    " << T.GetHour() << ':' << T.GetMin() << endl;

    return output;
}

istream& operator >> (istream& input, Time& T)
{
    string temp;
    int tempInt;
    //get set for hour
    getline(input, temp, ':');
    tempInt = stoi(temp);
    T.SetHour(tempInt);
    //get set for year (int)
    getline(input, temp, ',');
    tempInt = stoi(temp);
    T.SetMin(tempInt);

    return input;
}
