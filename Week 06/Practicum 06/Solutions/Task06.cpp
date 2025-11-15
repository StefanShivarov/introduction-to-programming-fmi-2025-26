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

int binarySearch(const int* arr, int size, int x) {
    int leftIndex = 0, rightIndex = size - 1;

    while (leftIndex <= rightIndex) {
        // int midIndex = (leftIndex + rightIndex) / 2; // this might cause an issue
        // , because leftIndex + rightIndex might become bigger than the largest possible value of type int
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2; // this is better

        if (arr[midIndex] == x) {
            return midIndex;
        }

        if (arr[midIndex] < x) {
            leftIndex = midIndex + 1;
        }
        else {
            rightIndex = midIndex - 1;
        }
    }

    return -1;
}

int main() {
    unsigned n;
    cin >> n;
    int arr[MAX_SIZE];
    readArray(arr, n);
    cout << "Search for number: ";
    unsigned x;
    cin >> x;
    // Important: the array must be sorted for binary search to work!
    int result = binarySearch(arr, n, x);
    if (result == -1) {
        cout << "No, " << x << " is not in the array.";
    } else {
        cout << "Yes, " << x << " is in the array at index " << result << ".";
    }
}
