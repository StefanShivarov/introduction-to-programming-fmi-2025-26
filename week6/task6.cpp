#include <iostream>
using namespace std;

int binarySearch(const int* arr, int size, int x) {
    int leftIndex = 0, rightIndex = size - 1;
    while (leftIndex <= rightIndex)
        if (arr[leftIndex + (rightIndex - leftIndex) / 2] == x)
            return leftIndex + (rightIndex - leftIndex) / 2;
        else if (arr[leftIndex + (rightIndex - leftIndex) / 2] < x)
            leftIndex += (rightIndex - leftIndex) / 2 + 1;
        else
            rightIndex = leftIndex + (rightIndex - leftIndex) / 2 - 1;
    return -1;
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cout << "x: ";
    cin >> x;
    if (binarySearch(a, n, x) == - 1)
        cout << "No, " << x << " is not in the array.";
    else
        cout << "Yes, " << x << " is in the array.";
}