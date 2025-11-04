#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// return true if found x in arr, else false
bool linearSearch(int* arr, unsigned length, int x) {
    for (unsigned i = 0; i < length; i++) {
        if (arr[i] == x) {
            return true;
        }
    }
    return false;
}

// return index of first occurrence of x in arr
int findWithLinearSearch(int* arr, unsigned length, int x) {
    for (unsigned i = 0; i < length; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << linearSearch(arr, 5, 4) << endl; // true
    cout << linearSearch(arr, 5, 9) << endl; // false
    cout << findWithLinearSearch(arr, 5, 4) << endl; // 3 (4 is at index 3 in the array)
    cout << findWithLinearSearch(arr, 5, 10) << endl; // -1 (not in the array)
}
