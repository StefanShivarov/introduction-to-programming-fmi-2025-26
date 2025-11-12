#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool isLeapYear(const unsigned year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

unsigned daysInMonth(const unsigned month, const unsigned year) {
    if (month < 1 || month > 12) {
        return 0;
    }
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if ((month % 2 != 0 && month <= 7) || (month % 2 == 0 && month > 7)) {
        return 31;
    }
    return 30;
}

bool isValidDate(const unsigned day, const unsigned month, const unsigned year) {
    if (month < 1 || month > 12) {
        return false;
    }
    unsigned maxDays = daysInMonth(month, year);
    return day >= 1 && day <= maxDays;
}


void addDays(unsigned& day, unsigned& month, unsigned& year, unsigned n) {
    while (n > 0) {
        unsigned daysInCurrentMonth = daysInMonth(month, year);
        if (daysInCurrentMonth == 0) {
            return;
        }

        if (day + n <= daysInCurrentMonth) {
            day += n;
            break;
        }

        n -= (daysInCurrentMonth - day + 1);
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            ++year;
        }
    }
}

int main() {
    unsigned day, month, year, n;
    cout << "Enter day, month, year: ";
    cin >> day >> month >> year;

    if (!isValidDate(day, month, year)) {
        cout << "Invalid date." << endl;
        return 1;
    }

    cout << "Enter number of days to add: ";
    cin >> n;

    addDays(day, month, year, n);

    cout << "New date: " << day << ' ' << month << ' ' << year << endl;
}
