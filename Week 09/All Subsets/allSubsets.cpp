#include <iostream>
using namespace std;

const unsigned MAX_SIZE = 50;

void readArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printSubset(const int* arr, int size, unsigned mask) {
    cout << "{";
    for (int i = 0; i < size; i++) {
        if (mask & 1) {
            cout << arr[i] << " ";
        }

        mask >>= 1;
    }

    cout << "}" << endl;
}

void printSubsets(const int* arr, int size) {
    unsigned subsetsCount = 1 << size;
    for (int i = 0; i < subsetsCount; i++) {
        printSubset(arr, size, i);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[MAX_SIZE];
    readArr(arr, n);
    printSubsets(arr, n);
}
