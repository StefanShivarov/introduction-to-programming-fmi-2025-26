#include <iostream>
using namespace std;

constexpr int MAX = 50;
int pow(const int base, const int exp) {
    int result = 1;
    for (int i = 1; i <= exp; i++)
        result *= base;
    return result;
}
int fromKthBaseToDecimal(const char num[MAX], const int n, const int k) {
    int result = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (num[i] >= '0' && num[i] <= '9')
            result += (num[i] - '0') * pow(k, n - 1 - i);
        else if (num[i] >= 'A' && num[i] <= 'F')
            result += (num[i] - 'A' + 10) * pow(k, n - 1 - i);
    }
    return result;
}
int main() {
    int n, k, n1, k1;
    char num[MAX], num1[MAX];
    cin >> n >> k >> num >> n1 >> k1 >> num1;
    if (fromKthBaseToDecimal(num, n, k) == fromKthBaseToDecimal(num1, n1, k1))
        {cout << "true";}
    else
        cout << "false";
}