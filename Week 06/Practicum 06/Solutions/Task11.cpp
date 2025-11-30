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

void printArray(const int* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void mergeArrays(const int* first, unsigned n, const int* second, unsigned m, int* result) {
    unsigned resultIndex = 0, firstIndex = 0, secondIndex = 0;
    while (firstIndex < n && secondIndex < m) {
        if (first[firstIndex] <= second[secondIndex]) {
            result[resultIndex++] = first[firstIndex++];
        } else {
            result[resultIndex++] = second[secondIndex++];
        }
    }

    while (firstIndex < n) {
        result[resultIndex++] = first[firstIndex++];
    }

    while (secondIndex < m) {
        result[resultIndex++] = second[secondIndex++];
    }
}

int main() {
    unsigned n, m;
    cin >> n;
    int first[MAX_SIZE];
    readArray(first, n);
    cin >> m;
    int second[MAX_SIZE];
    readArray(second, m);
    int result[MAX_SIZE * 2];
    mergeArrays(first, n, second, m, result);
    printArray(result, n + m);
}
