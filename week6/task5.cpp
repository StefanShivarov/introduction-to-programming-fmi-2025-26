#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}
void bubbleSort(double* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        if (!swapped)
            break;
    }
}
void printArray(double* arr, size_t size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
int main() {
    int n;
    cin >> n;
    double arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bubbleSort(arr, n);
    printArray(arr, n);
}