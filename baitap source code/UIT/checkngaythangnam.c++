#include <iostream>

using namespace std;

bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

string isValidDate(int day, int month, int year)
{
    if (year <= 0)
    {
        return "Nam khong hop le.";
    }

    if (month < 1 || month > 12)
    {
        return "Thang khong hop le.";
    }

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year))
    {
        days_in_month[1] = 29;
    }

    if (day < 1 || day > days_in_month[month - 1])
    {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " la ngay khong hop le.";
    }

    return to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " la ngay hop le.";
}

int main()
{
    int day, month, year;
    cin >> day >> month >> year;

    cout << isValidDate(day, month, year) << endl;

    return 0;
}
