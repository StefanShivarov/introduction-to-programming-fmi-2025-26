#include <iostream>

int main() {

    int arr[] = {1, 2, 3, 4, 5};

    int* maxPtr = arr; 

    for (int* p = arr; p < arr + N; p++) {
        if (*p > *maxPtr) {
            maxPtr = p;
        }
    }

    std::cout << maxPtr;
}
