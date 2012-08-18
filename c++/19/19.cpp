#include <iostream>
using namespace std;

bool isLeapYear(int year)
{
    if (year % 4 == 0)
        return 1;
    else 
        return 0;
}

int daysIn(int month, int year)
{
    if (month == 2 && isLeapYear(year))
        return 29;

    switch (month){
        case 1:
            return 31;
        case 2:
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }
}


int main()
{
    int day, month, year, weekday, sundays;
    weekday = -1;
    sundays = 0;

    for (year = 1901; year <= 2000; year++){
        for (month = 1; month <= 12; month++){
            cout << month << " " << daysIn(month, year) << " " << year << endl;
            for (day = 1; day <= daysIn(month, year); day++){
                weekday = (weekday + 1) % 7;
                if (weekday == 6 && day == 1)
                    sundays++;
            }
        }
    }

    cout << sundays;
}
