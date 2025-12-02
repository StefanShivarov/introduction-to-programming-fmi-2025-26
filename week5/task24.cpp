#include <iostream>
using namespace std;

bool isLeap(unsigned int year) {
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}
bool isValid(unsigned int day, unsigned int month, unsigned int year) {
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day >= 1 && day <= 31)
        return true;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day >= 1 && day <= 30)
        return true;
    if (month == 2)
        if (isLeap(year) && day >= 1 && day <= 29)
            return true;
        else if (!isLeap(year) && day >= 1 && day <= 28)
            return true;
    return false;
}
void nextDay(unsigned int &day, unsigned int &month, unsigned int &year) {
    if (isValid(day + 1, month, year))
        day++;
    else if (isValid(1, month + 1, year))
        day = 1, month++;
    else
        day = 1, month = 1, year++;
}
int main() {
    unsigned int day, month, year;
    cout << "Enter day, month, year: ";
    cin >> day >> month >> year;
    unsigned int n;
    cout << "Enter number of days to add: ";
    cin >> n;
    for (unsigned int i = 0; i < n; i++)
        nextDay(day, month, year);
    cout << "New date: " << day << " " << month << " " << year << endl;
}