#include <iostream>
using namespace std;

int process(int* const a, const int* const end, int* const r) {
    // a -> a1[0] , end -> element after last element from a1 , r -> a2[0]
    
    int* p = a + 1; // p -> a1[1]
    const int* const q = end - 1; // q -> a1[3]

    *(r + 1) = *p + *(q - 1); // a2: [10, 10, 30]
    *(a + 2) = *r - *a; // a1: [2, 4, 8, 8]

    p++; // p -> a1[2]

    cout << *p << " " << *(a + 2) << " " << *(r + 1) << " "; // 8 8 10
    cout << (q - p) << " " << (&a[3] - q) << " "; // 1 0

    if ((*p > 0) & (*r > 0)) return *(r + 1); // returns 10
    else return *p;
}

int main() {
    int a1[4] = {2, 4, 6, 8};
    int a2[] = {10, 20, 30};
    int* r = a2;

    int result = process(a1, a1 + 4, r);
    cout << result << endl; // 10
    return 0;
}

// Final output: 8 8 10 1 0 10
