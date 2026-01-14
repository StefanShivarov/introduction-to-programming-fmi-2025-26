#include <iostream>
using namespace std;

bool isDivisibleByNeighbor(const int arr[], const int n, const int i) {
    if (n == 1)
        return true;
    if (n < 1)
        return false;
    if (!i)
        return !(arr[i] % arr[i + 1]);
    if (i == n - 1)
        return !(arr[i] % arr[i - 1]);
    return !(arr[i] % arr[i + 1]) || !(arr[i] % arr[i - 1]);
}
void readArray(int arr[], const int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
size_t getCountOfElementsDivisibleByNeighbor(const int arr[], const int n) {
    size_t counter = 0;
    for (int i = 0; i < n; i++)
        if (isDivisibleByNeighbor(arr, n, i))
            counter++;
    return counter;
}
int* modifiedArray(const int arr[], const int n) {
    size_t counter = getCountOfElementsDivisibleByNeighbor(arr, n);
    int* arr1 = new int[counter];
    counter = 0;
    for (int i = 0; i < n; i++)
        if (isDivisibleByNeighbor(arr, n, i))
            arr1[counter++] = arr[i];
    return arr1;
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    readArray(arr, n);
    const int* arr1 = modifiedArray(arr, n);
    const size_t counter = getCountOfElementsDivisibleByNeighbor(arr, n);
    for (int i = 0; i < counter; i++)
        cout << arr1[i] << " ";
    delete[] arr;
    delete[] arr1;
}
