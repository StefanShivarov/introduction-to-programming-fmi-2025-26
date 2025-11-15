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

double average(const int* arr, unsigned size) {
    double sum = 0;
    for (unsigned i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    unsigned n;
    cin >> n;
    int arr[MAX_SIZE];
    readArray(arr, n);

    cout << "Average: " << average(arr, n) << endl;
}
