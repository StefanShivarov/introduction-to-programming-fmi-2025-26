#include <iostream>
using namespace std;

void toString(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}
void swap(int &a, int &b) {
    a += b;
    b = a - b;
    a -= b;
}
void swapSegments(int array[], int from, int to) {
    while (from < to)
        swap(array[from++], array[to--]);
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    swapSegments(arr, 0, n / 2 - 1 + n % 2);
    swapSegments(arr, n / 2 + n % 2, n - 1);
    toString(arr, n);
}