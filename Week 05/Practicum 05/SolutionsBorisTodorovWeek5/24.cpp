#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool isLeap(int year)
{
    if (year % 4 == 0)
    {
        if (year % 400==0)
        {
            return true;
        }
        else if (year % 100 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}
bool isDateValid(int day, int month,int year)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day <= 31 && day>0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day <= 30 && day > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (month == 2)
    {
        if (isLeap(year))
        {
            if (day <= 29 && day > 0)
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
            if (day <= 28 && day > 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if (month > 12 || month < 1)
    {
        return false;
    }
}
void updateDate(int& day, int& month, int& year, int daysToAdd)
{
    day += daysToAdd;
    while (!isDateValid(day, month, year))
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if (day > 31)
            {
                day -= 31;
                month++;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day > 30)
            {
                day -= 30;
                month++;
            }
        }
        else if (month == 2)
        {
            if (isLeap(year))
            {
                if (day > 29)
                {
                    day -= 29;
                    month++;
                }
            }
            else
            {
                if (day > 28)
                {
                    day -= 28;
                    month++;
                }
            }
        }
        if (month > 12)
        {
            month -= 12;
            year++;
        }
    }
}
int main()
{
    bool isValid = false;
    int daysToAdd = 0;
    int day=0, month=0, year=0;
    do
    {
        cout << "Enter day, month, year: ";cin >> day >> month >> year;
    }
    while (!isDateValid(day, month, year));
    cout << "Enter number of days to add: "; cin >> daysToAdd;
    updateDate(day, month, year, daysToAdd);
    cout << "New date: " << day << " " << month << " " << year;

}
