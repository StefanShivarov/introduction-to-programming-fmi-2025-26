#include <iostream>
using namespace std;

void makeNull(int*& p) {
    p = nullptr;
}

int main()
{
    int a = 5;
    int* ptr = &a;
    makeNull(ptr);
}
