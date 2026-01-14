#include <iostream>
using namespace std;

int pow(int base, int power) {
    int result = 1;
    for (int i = 1; i <= power; i++)
        result *= base;
    return result;
}
int log(int k, int n) {
    int power = 1;
    while (pow(k, power) <= n)
        power++;
    return power - 1;
}
int main() {
    int k, n;
    cin >> k >> n;
    cout << "log_" << k << "(" << n << ")" << " -> " << log(k, n) << endl;
}