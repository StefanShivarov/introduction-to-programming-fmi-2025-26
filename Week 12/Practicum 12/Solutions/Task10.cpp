#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int getSumOfDigits(int num) {
    int result = 0;
    while (num != 0) {
        result += num % 10;
        num /= 10;
    }
    return result;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int* getSumsOfDigits(const int* arr, unsigned size, int& maxSum) {
    int* sums = new int[size];
    maxSum = 0;
    for (unsigned i = 0; i < size; i++) {
        sums[i] = getSumOfDigits(arr[i]);
        maxSum = max(maxSum, sums[i]);
    }
    return sums;
}

void printNumsWithSumsInRange(const int* arr, unsigned size) {
    int maxSum = 0;
    int* sums = getSumsOfDigits(arr, size, maxSum);

    for (unsigned i = 0; i <= maxSum; i++) {
        bool foundSum = false;
        for (unsigned j = 0; j < size; j++) {
            if (sums[j] == i) {
                foundSum = true;
                cout << arr[j] << ' ';
            }
        }
        if (!foundSum) {
            cout << -1;
        }
        cout << endl;
    }

    delete[] sums;
}

int main() {
    unsigned n;
    cin >> n;
    int* arr = new int[n];
    for (unsigned i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printNumsWithSumsInRange(arr, n);
    delete[] arr;
}
