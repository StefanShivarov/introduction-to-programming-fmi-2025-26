#include <iostream>
using namespace std;

int findMaxMin(const int* arr, size_t size, int& minVal, int& maxVal) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return (minVal + maxVal) / 2;
}
int main() {
    size_t n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int minVal = INT_MAX, maxVal = INT_MIN;
    cout << findMaxMin(arr, n, minVal, maxVal);
}