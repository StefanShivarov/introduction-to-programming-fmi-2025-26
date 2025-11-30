#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_SIZE = 50;

void readArray(unsigned* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(const unsigned* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// Returns -1 if a < b lexicographically, 1 if a > b, 0 if equal
int compareLex(unsigned long long a, unsigned long long b) {
    // Find the highest power of 10 less than or equal to a and b
    unsigned long long powA = 1;
    unsigned long long powB = 1;
    while (powA <= a / 10) {
        powA *= 10;
    }
    while (powB <= b / 10) {
        powB *= 10;
    }

    while (powA > 0 && powB > 0) {
        unsigned digitA = a / powA;
        unsigned digitB = b / powB;

        if (digitA < digitB) return -1;
        if (digitA > digitB) return 1;

        a %= powA;
        b %= powB;

        powA /= 10;
        powB /= 10;
    }

    // If one number still has digits left, it's lexicographically larger
    if (powA > 0) {
        return 1;
    }
    if (powB > 0) {
        return -1;
    }

    return 0;
}


void swap(unsigned& a, unsigned& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void sortLex(unsigned* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < size; j++) {
            if (compareLex(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    unsigned n;
    cin >> n;
    unsigned arr[MAX_SIZE];
    readArray(arr, n);
    sortLex(arr, n);
    printArray(arr, n);
}
