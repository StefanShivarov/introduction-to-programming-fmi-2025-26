#include <iostream>
using namespace std;

void printArr(const int arr[], const int length) {
    for (int i = 0; i < length; i++)
        cout << *(arr + i) << " ";
}
int main() {
    constexpr int length = 4;
    constexpr int arr[] = {1, 3, 6, 9};
    printArr(arr, length);
}