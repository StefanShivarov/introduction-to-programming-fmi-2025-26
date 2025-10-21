#include <iostream>

using namespace std;

int main() {
    int index = 0;
    cin >> index;

    int current = 1;
    int previous = 0;
    for (int i = 2; i < index; i++) {
        int next = current + previous;
        previous = current;
        current = next;
    }


    if (index == 1) {
        cout << 0;
    } else {
        cout << current;
    }

    return 0;
}