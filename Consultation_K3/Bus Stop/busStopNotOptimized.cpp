#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const unsigned LINES_COUNT = 32;

int extractHour(const char* time) {
    return (time[0] - '0') * 10 + (time[1] - '0');
}

void addRecord(bool hours[][LINES_COUNT], int hour, int line) {
    if (hour >= 0 && hour < 24 && line >= 1 && line <= LINES_COUNT) {
        hours[hour][line - 1] = true;
    }
}

void combineLines(const bool hours[][LINES_COUNT],
                  int startHour, int endHour,
                  bool result[]) {
    for (int h = startHour; h < endHour; h++) {
        for (int i = 0; i < LINES_COUNT; i++) {
            if (hours[h][i]) {
                result[i] = true;
            }
        }
    }
}

void printLines(const bool lines[]) {
    for (int i = 0; i < LINES_COUNT; i++) {
        if (lines[i]) {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    bool hours[24][LINES_COUNT] = { false };

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
            cout << "Hour must be between 0 and 23!";
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

    bool combined[LINES_COUNT] { false };
    combineLines(hours, startHour, endHour, combined);
    printLines(combined);

    return 0;
}
