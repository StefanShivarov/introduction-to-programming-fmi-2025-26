#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void readArray(int* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(const int* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void reversePartOfArray(int* arr, unsigned size, unsigned from, unsigned to) {
    // validate arguments
    if (from >= size || to >= size) {
        return;
    }

    while (from < to) {
        swap(arr[from++], arr[to--]);
    }
}

int main() {
    const int n = 7;
    int arr[n];
    readArray(arr, n);

    // if n is odd, we want the bigger half first, then the rest
    int remainder = n % 2; // 0 if n is even, 1 if n is odd
    reversePartOfArray(arr, n, 0, n / 2 - (1 - remainder)); // first half
    reversePartOfArray(arr, n, n / 2 + remainder, n - 1); // second half

    printArray(arr, n);
}
