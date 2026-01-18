#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
size_t getSizeOfCounter(const int arr1[], const int arr2[], const int n, const int m, const int k) {
    size_t counter = 0;
    for (int i = 0; i < n; i++)
        if (!(arr1[i] % k))
            counter++;
    for (int i = 0; i < m; i++)
        if (!(arr2[i] % k))
            counter++;
    return counter;
}
int* func(const int arr1[], const int arr2[], const int n, const int m, const int k) {
    size_t counter = getSizeOfCounter(arr1, arr2, n, m, k);
    int* arr = new int[counter];
    counter = 0;
    for (int i = 0; i < n; i++)
        if (!(arr1[i] % k))
            arr[counter++] = arr1[i];
    for (int i = 0; i < m; i++)
        if (!(arr2[i] % k))
            arr[counter++] = arr2[i];
    return arr;
}
int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    cin >> k;
    const int* arr = func(arr1, arr2, n, m, k);
    const size_t counter = getSizeOfCounter(arr1, arr2, n, m, k);
    for (int i = 0; i < counter; i++)
        cout << arr[i] << " ";
    delete[] arr;
}