#include <iostream>
#include <cmath>
using namespace std;

bool isLeap(unsigned year) {
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 4 == 0 && year % 100 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidDate(unsigned day, unsigned month, unsigned year) {
    if (month < 1 || month > 12)
    {
        return false;
    }
    unsigned daysInMonth;
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        daysInMonth = 31; break;
    case 4: case 6: case 9: case 11:
        daysInMonth = 30; break;
    case 2:
        daysInMonth = isLeap(year) ? 29 : 28; break;
    }
    return day >= 1 && day <= daysInMonth;
}

void nextDay(unsigned& day, unsigned& month, unsigned& year) {
    unsigned daysInMonth;
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        daysInMonth = 31; break;
    case 4: case 6: case 9: case 11:
        daysInMonth = 30; break;
    case 2:
        daysInMonth = isLeap(year) ? 29 : 28; break;
    }
    day++;
    if (day > daysInMonth)\
    {
        day = 1;
        month++;
        if (month > 12) 
        {
            month = 1;
            year++;
        }
    }
}

void addDays(unsigned& day, unsigned& month, unsigned& year, unsigned n) {
    for (unsigned i = 0; i < n; i++) 
    {
        nextDay(day, month, year);
    }
}

int main() {
    unsigned day, month, year, n;
    cin >> day >> month >> year >> n;
    if (isValidDate(day, month, year)==false) 
    {
        cout << "Invalid date";
    }
    addDays(day, month, year, n);
    cout << day << " " << month << " " << year;
}