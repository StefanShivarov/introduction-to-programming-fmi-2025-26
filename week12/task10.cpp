#include <iostream>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n)
        sum += n % 10, n /= 10;
    return sum;
}
int getLargestBySumOfDigits(const int arr[], const int n) {
    int largest = digitSum(arr[0]);
    for (int i = 1; i < n; i++)
        if (digitSum(arr[i]) > largest)
            largest = digitSum(arr[i]);
    return largest;
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    const int s = getLargestBySumOfDigits(arr, n);
    for (int i = 0; i <= s; i++) {
        bool printed = false;
        for (int j = 0; j < n; j++)
            if (digitSum(arr[j]) == i)
                cout << arr[j] << " ", printed = true;
        if (!printed)
            cout << -1 << endl;
        else
            cout << endl;
    }
    delete[] arr;
}