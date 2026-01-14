#include <iostream>
using namespace std;

bool check(const int* a, int** b) {
    return *b == a;
}
int main() {
    int a;
    int* pa = &a;
    int** pb = &pa;
    cout << check(pa, pb);
}