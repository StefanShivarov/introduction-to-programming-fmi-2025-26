#include <iostream>
using namespace std;

int getWhole(const float& a) {
    const float* pa = &a;
    return *pa;
}
int main() {
    constexpr float f  = 1.5f;
    cout << getWhole(f);
}