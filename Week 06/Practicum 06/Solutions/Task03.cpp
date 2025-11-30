#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_SIZE = 50;

void readArray(int* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool consistsOfUniqueNumbers(const int* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    unsigned n;
    cin >> n;
    int arr[MAX_SIZE];
    readArray(arr, n);

    cout << (consistsOfUniqueNumbers(arr, n) ?
            "Yes, the sequence consists of distinct elements."
            : "No, the sequence does not consist of distinct elements.");
}
