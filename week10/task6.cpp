#include <iostream>
using namespace std;

constexpr int MAX = 100;
const int* getAddress(const int arr[], const int index) {
    return &(arr[index]);
}
void readArray(int arr[], const int size) {
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}
int getIndexOfMax(const int arr[], const int size) {
    int max = arr[0], index = 0;
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i], index = i;
    return index;
}
int main() {
    int arr[MAX];
    int n;
    cin >> n;
    readArray(arr, n);
    cout << getAddress(arr, getIndexOfMax(arr, n));
}