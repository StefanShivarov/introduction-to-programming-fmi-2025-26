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

bool isMonotonicallyDecreasing(const int* arr, unsigned size) {
    for (unsigned i = 1; i < size; i++) {
        if (arr[i] > arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    unsigned n;
    cin >> n;
    int arr[MAX_SIZE];
    readArray(arr, n);

    cout << (isMonotonicallyDecreasing(arr, n) ?
            "Тhe series is monotonically decreasing."
            : "Тhe series is not monotonically decreasing.");
}
