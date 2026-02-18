#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}
void bubbleSort(int* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        if (!swapped)
            break;
    }
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    int b[n + m];
    for (int i = n; i < n + m; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    bubbleSort(b, n + m);
    for (int i = 0; i < n + m; i++)
        cout << b[i] << " ";
}