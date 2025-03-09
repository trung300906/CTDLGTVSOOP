#ifndef DEFINE_HPP
#define DEFINE_HPP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct day_time
{
private:
    int day, month, year;
    vector<int> mmmm = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool leap_year()
    {
        if (year % 4 == 0 && year % 100 != 0)
            return true;
        if (year % 400 == 0)
            return true;
        return false;
    }

public:
    day_time(int day_, int month_, int year_) : day(day_), month(month_), year(year_)
    {
        if (leap_year())
        {
            mmmm[2] = 29;
        }
    };
    day_time()
    {
        cout << "type in day: ";
        cin >> day;
        cout << "type in month: ";
        cin >> month;
        cout << "type in year: ";
        cin >> year;
        if (leap_year())
        {
            mmmm[2] = 29;
        }
    }
    friend ostream &operator<<(ostream &out, const day_time &op)
    {
        if (op.year >= 0)
            out << "day: " << op.day << " month: " << op.month << " year: " << op.year << endl;

        return out;
    }
    day_time find_next_day()
    {
        day++;
        if (day > mmmm[month])
        {
            day = 1;
            month++;
        }
        if (month > 12)
        {
            year++;
            month = 1;
        }
        return day_time(day, month, year);
    }
    day_time find_day_before()
    {
        day--;
        if (day == 0)
        {
            month--;
            if (month == 2)
                day = mmmm[month];
            if (month == 0)
            {
                year--;
                month = 12;
                day = 31;
            }
        }
        return day_time(day, month, year);
    }
};
#endif