#include <iostream>
using std::cout;

bool pointsToSame(int* valuePtr, int** ptrToPtr) {
    return *ptrToPtr == valuePtr;
}

int main() {
    int x = 10;

    int* p1 = &x; 
    int* p2 = &x;
    int** pp = &p2;

    cout << pointsToSame(p1, pp); // true
}
