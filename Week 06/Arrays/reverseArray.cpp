#include <iostream>
using std::cin;
using std::cout;

void swap(int& a, int& b) {
	a = a + b;
    b = a - b;
    a = a - b;
}

void reverseArray(int* arr, unsigned length) {
	for (int i = 0; i < length / 2; i++) {
		swap(arr[i], arr[length - i - 1]);
	}
}
