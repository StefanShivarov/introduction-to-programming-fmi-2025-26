#include <iostream>
using namespace std;

void shiftToRight(int arr[], const int n) {
    for (int i = n - 1; i >= 0; i--)
        arr[i] = arr[i - 1];
}
void modify(int arr[], const int n) {
    if (n < 1)
        return;
    const int temp = arr[n - 1];
    shiftToRight(arr, n);
    arr[0] = temp;
}
int main() {
    int n, k;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    for (int i = 0; i < k; i++)
        modify(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    delete[] arr;
}