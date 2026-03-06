#include <iostream>
using namespace std;

constexpr int MAX = 100;
bool getKthBitFromRightToLeft(const unsigned num, const int k) {
    return num & (1 << k);
}
void setBitToZero(unsigned& number, const int index) {
    unsigned int mask = 1;
    mask <<= index, mask = ~mask, number &= mask;
}
void setBitToOne(unsigned& number, const int index) {
    unsigned int mask = 1;
    mask <<= index, number |= mask;
}
unsigned unionOf(const unsigned calendar1, const unsigned calendar2) {
    return calendar1 | calendar2;
}
unsigned crossSectionOf(const unsigned calendar1, const unsigned calendar2) {
    return calendar1 & calendar2;
}
int main() {
    unsigned calendar = 0;
    unsigned calendar1 = 0;
    char operation[MAX];
    int number;
    while (cin >> operation, operation[1] != 'N')
        if (operation[2] == 'D') {
            cin >> number;
            setBitToOne(calendar, number);
            cout << "Added exam on day " << number << "." << endl;
        }
        else if (operation[2] == 'E') {
            cin >> number;
            if (getKthBitFromRightToLeft(calendar, number))
                cout << "Yes, there is an exam on day " << number << "." << endl;
            else
                cout << "No, there is no exam on day " << number << "." << endl;
        }
        else if (operation[2] == 'U') {
            int counter = 0;
            for (int i = 1; i <= 31; i++)
                if (getKthBitFromRightToLeft(calendar, i))
                    counter++;
            cout << "Exam days count: " << counter << endl;
        }
        else if (operation[2] == 'R') {
            for (int i = 1; i <= 31; i++)
                if (getKthBitFromRightToLeft(calendar, i)) {
                    cout << "First exam day: " << i << endl;
                    break;
                }
        }
        else if (operation[2] == 'S') {
            cout << "Exam days: ";
            for (int i = 1; i <= 31; i++)
                if (getKthBitFromRightToLeft(calendar, i))
                    cout << i << " ";
            cout << endl;
        }
        else if (operation[2] == 'M') {
            cin >> number;
            setBitToZero(calendar, number);
            cout << "Removed exam from day " << number << "." << endl;
        }
    cout << "Enter info for second calendar: " << endl;
    while (cin >> operation, operation[1] != 'N')
        if (operation[2] == 'D') {
            cin >> number;
            setBitToOne(calendar1, number);
            cout << "Added exam on day " << number << "." << endl;
        }
        else if (operation[2] == 'E') {
            cin >> number;
            if (getKthBitFromRightToLeft(calendar1, number))
                cout << "Yes, there is an exam on day " << number << "." << endl;
            else
                cout << "No, there is no exam on day " << number << "." << endl;
        }
        else if (operation[2] == 'U') {
            int counter = 0;
            for (int i = 1; i <= 31; i++)
                if (getKthBitFromRightToLeft(calendar1, i))
                    counter++;
            cout << "Exam days count: " << counter << endl;
        }
        else if (operation[2] == 'R') {
            for (int i = 1; i <= 31; i++)
                if (getKthBitFromRightToLeft(calendar1, i)) {
                    cout << "First exam day: " << i << endl;
                    break;
                }
        }
        else if (operation[2] == 'S') {
            cout << "Exam days: ";
            for (int i = 1; i <= 31; i++)
                if (getKthBitFromRightToLeft(calendar1, i))
                    cout << i << " ";
            cout << endl;
        }
        else if (operation[2] == 'M') {
            cin >> number;
            setBitToZero(calendar1, number);
            cout << "Removed exam from day " << number << "." << endl;
        }
    cout << "Union of both calendars:" << endl;
    unsigned temp = unionOf(calendar, calendar1);
    int counter = 0;
    for (int i = 1; i <= 31; i++)
        if (getKthBitFromRightToLeft(temp, i))
            counter++;
    cout << "Exam days count: " << counter << endl;
    for (int i = 1; i <= 31; i++)
        if (getKthBitFromRightToLeft(temp, i)) {
            cout << "First exam day: " << i << endl;
            break;
        }
    cout << "Exam days: ";
    for (int i = 1; i <= 31; i++)
        if (getKthBitFromRightToLeft(temp, i))
            cout << i << " ";
    cout << endl;
    cout << "Cross-section of both calendars:" << endl;
    temp = crossSectionOf(calendar, calendar1);
    counter = 0;
    for (int i = 1; i <= 31; i++)
        if (getKthBitFromRightToLeft(temp, i))
            counter++;
    cout << "Exam days count: " << counter << endl;
    for (int i = 1; i <= 31; i++)
        if (getKthBitFromRightToLeft(temp, i)) {
            cout << "First exam day: " << i << endl;
            break;
        }
    cout << "Exam days: ";
    for (int i = 1; i <= 31; i++)
        if (getKthBitFromRightToLeft(temp, i))
            cout << i << " ";
}