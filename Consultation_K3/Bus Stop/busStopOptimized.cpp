#include <iostream>
using std::cin;
using std::cout;
using std::endl;


// 96 bytes instead of 768 !

const unsigned LINES_COUNT = 32;

int extractHour(const char* time) {
    return (time[0] - '0') * 10 + (time[1] - '0');
}

void addRecord(int* hours, int hour, int line) {
    if (hour >= 0 && hour < 24 && line >= 1 && line <= LINES_COUNT) {
        hours[hour] |= (1 << (line - 1));
    }
}

int combineLinesFromHours(const int* hours, int startHour, int endHour) {
    int combined = 0;
    for (int i = startHour; i < endHour; i++) {
        combined |= hours[i];
    }
    return combined;
}

void printLines(int mask) {
    for (int i = 0; i < LINES_COUNT; i++) {
        if (mask & (1 << i)) {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    int hours[24] {0};
    for (int i = 0; i < N; i++) {
        char time[6];
        int line;
        cin >> time >> line;

        if (time[2] != ':') {
            cout << "Invalid time format!";
            return 1;
        }
        time[5] = '\0';

        int hour = extractHour(time);
        if (hour > 23) {
            cout << "Hour must be between 0 and 24!";
            return 1;
        }
        addRecord(hours, hour, line);
    }

    int startHour, endHour;
    cin >> startHour >> endHour;

    if (startHour >= endHour || startHour < 0 || endHour > 24) {
        cout << "Invalid input... Start hour must be before end hour, and they must be valid hours between 0 and 24" << endl;
        return 1;
    }

    int combined = combineLinesFromHours(hours, startHour, endHour);
    printLines(combined);
}
