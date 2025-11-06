#include <iostream>

using std::cin;
using std::cout;
using std::endl;

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
    const int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    cout << binarySearch(arr, n, 4) << endl; // 3
    cout << binarySearch(arr, n, 10) << endl; // -1
}
