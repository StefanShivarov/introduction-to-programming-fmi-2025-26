#include <iostream>
using namespace std;

void changeValueToNP(int*& pointer) {
    pointer = nullptr;
}
int main() {
    int a = 5;
    int* pointer = &a;
    cout << pointer << endl;
    changeValueToNP(pointer);
    cout << pointer << endl;
}