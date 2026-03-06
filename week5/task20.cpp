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
    int n;
    cin >> n;
    int result = n - pow(2, log(2, n)) < pow(2, log(2, n) + 1) - n ? pow(2, log(2, n)) : pow(2, log(2, n) + 1);
    cout << result;
}