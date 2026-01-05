#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int* rotateRight(const int* arr, unsigned size, int k) {
    if (size == 0) {
        return nullptr;
    }

    k %= size;

    int* result = new int[size];
    for (unsigned i = 0; i < size; i++) {
        unsigned newIndex = (i + k) % size;
        result[newIndex] = arr[i];
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
    unsigned k;
    cin >> k;

    int* result = rotateRight(arr, n, k);
    for (unsigned i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    delete[] arr;
}
