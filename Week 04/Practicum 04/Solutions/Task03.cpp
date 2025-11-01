#include <iostream>

using std::cin;

int askUser(const int from, const int to) {
    int num;
    while (true) {
        cin >> num;
        if (num >= from && num <= to) {
            return num;
        }
    }
}
