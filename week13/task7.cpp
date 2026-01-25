#include <iostream>
using namespace std;

void transfer(const int* src, int* dest, const int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}
void resize(int*& arr, int &n) {
    int* temp = new int[n + 1];
    transfer(arr, temp, n++);
    delete[] arr;
    arr = temp;
}
void shift(int* arr, const int n, const int from) {
    for (int i = n - 1; i > from; i--) {
        arr[i] = arr[i - 1];
    }
}
void insertAtCorrectPos(int*& arr, int& n, const int index, const int element) {
    if (index == n) {
        resize(arr, n);
        arr[index] = element;
    }
    else if (arr[index] >= element) {
        resize(arr, n);
        shift(arr, n, index);
        arr[index] = element;
    }
    else {
        insertAtCorrectPos(arr, n, index + 1, element);
    }
}
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int element;
    cin >> element;
    constexpr int index = 0;
    insertAtCorrectPos(arr, n, index, element);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
}