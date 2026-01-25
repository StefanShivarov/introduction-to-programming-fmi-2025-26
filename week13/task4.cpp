#include <iostream>
using namespace std;

bool isAscending(int* arr, const int n) {
    if (n - 2 < 0) {
        return true;
    }
    if (arr[n - 1] > arr[n - 2]) {
        return isAscending(arr, n - 1);
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    const bool result = isAscending(arr, n);
    if (result) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    delete[] arr;
}