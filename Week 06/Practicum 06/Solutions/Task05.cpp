#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_SIZE = 50;

void readArray(double* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(const double* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void swap(double& a, double& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void selectionSort(double* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
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
    double arr[MAX_SIZE];
    readArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
}
