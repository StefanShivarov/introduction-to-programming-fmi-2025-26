#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int getAverageAsInt(const int* arr, unsigned size) {
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int absoluteValue(int n) {
    return n < 0 ? -n : n;
}

int findMaxMin(const int* arr, unsigned size, int& minVal, int& maxVal) {
    int avg = getAverageAsInt(arr, size);
    minVal = maxVal = arr[0];
    int minDiff = absoluteValue(arr[0] - avg), result = arr[0];
    for (unsigned i = 1; i < size; i++) {
        int currentDiff = absoluteValue(arr[i] - avg);
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            result = arr[i];
        }
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    return result;
}

void readArray(int* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int main() {
    int min, max;
    const int n = 6;
    int arr[n];

    readArray(arr, n);

    cout << "Closest to average: " << findMaxMin(arr, n, min, max) << endl;
    cout << "Max: " << max << " Min: " << min << endl;
}
