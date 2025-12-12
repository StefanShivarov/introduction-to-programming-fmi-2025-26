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
        int temp = 0;
        if (num[i] >= '0' && num[i] <= '9')
            temp = num[i] - '0';
        else if (num[i] >= 'A' && num[i] <= 'F')
            temp = num[i] - 'A' + 10;
        result += temp * pow(k, n - 1 - i);
    }
    return result;
}
void fromDecimalToKthBase(char num[MAX], const int n, const int k, int number) {
    int pos = n - 1;
    while (pos >= 0) {
        if (number % k < 10)
            num[pos--] = number % k + '0';
        else
            num[pos--] = number % k + 'A' - 10;
        number /= k;
    }
}
int main() {
    int n, k;
    char num[MAX];
    cin >> n >> k >> num;
    fromDecimalToKthBase(num, n, k, fromKthBaseToDecimal(num, n, k) - 1);
    for (int i = 0; i < n; i++)
        {cout << num[i];}
}