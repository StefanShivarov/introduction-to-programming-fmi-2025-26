#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void selectionSort(int* arr, int size, bool (*comparatorFunc)(int, int)) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (comparatorFunc(arr[j], arr[minIndex])) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    const int n = 5;
    int arr[n] = {4, 2, 3, 5, 1};

    selectionSort(arr, n);
    printArray(arr, n); // 1 2 3 4 5
    cout << endl;

    // sorting by custom comparator function!
    selectionSort(arr, n, [](int a, int b){ return a > b; });
    printArray(arr, n); // 5 4 3 2 1
}
