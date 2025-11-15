#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_SIZE = 50;

void readArray(char* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool isSymmetric(const char* arr, unsigned size) {
    for (unsigned i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    unsigned n;
    cin >> n;
    char arr[MAX_SIZE];
    readArray(arr, n);

    cout << (isSymmetric(arr, n) ?
            "Yes, the array is symmetric."
            : "No, the array is not symmetric.");
}
