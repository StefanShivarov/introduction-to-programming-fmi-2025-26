#include <iostream>
using namespace std;

int lcm(int a, int b) {
    for (int i = a > b ? a : b; i <= a * b; i++)
        if (i % a == 0 && i % b == 0)
            return i;
    return -1;
}
int gcd(int a, int b) {
    for (int i = a < b ? a : b; i >= 1; i--)
        if (a % i == 0 && b % i == 0)
            return i;
    return -1;
}
int main() {
    int n;
    cin >> n;
    int num;
    cin >> num;
    int resultLcm = num;
    int resultGcd = num;
    for (int i = 1; i < n; i++) {
        cin >> num;
        resultLcm = lcm(resultLcm, num);
        resultGcd = gcd(resultGcd, num);
    }
    cout << "GCD = " << resultGcd << endl << "LCM = " << resultLcm << endl;
}