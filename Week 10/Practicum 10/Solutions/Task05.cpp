#include <iostream>
using namespace std;

int reinterpretFloatAsInt(float& f) {
    int* p = (int*)(&f); 
    return *p;
}
