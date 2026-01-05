#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool isDivisibleByNeighbor(const int* arr, unsigned size, unsigned i) {
    if (i > 0 && arr[i] % arr[i - 1] == 0) {
        return true;
    }
    if (i + 1 < size && arr[i] % arr[i + 1] == 0) {
        return true;
    }
    return false;
}

int* getElementsDivisibleByNeighbor(const int* arr, unsigned size, unsigned& resultSize) {
    resultSize = 0;

    for (unsigned i = 0; i < size; i++) {
        if (isDivisibleByNeighbor(arr, size, i)) {
            resultSize++;
        }
    }

    int* result = new int[resultSize];
    unsigned pos = 0;

    for (unsigned i = 0; i < size; i++) {
        if (isDivisibleByNeighbor(arr, size, i)) {
            result[pos++] = arr[i];
        }
    }

    return result;
}

int main() {
    unsigned n;
    cin >> n;

    int* arr = new int[n];
    for (unsigned i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unsigned resultSize;
    int* result = getElementsDivisibleByNeighbor(arr, n, resultSize);

    for (unsigned i = 0; i < resultSize; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;

    delete[] result;
    delete[] arr;

    return 0;
}
