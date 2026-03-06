#include <iostream>
using namespace std;

constexpr int MAX = 50;
int pow(const int base, const int exp) {
    int result = 1;
    for (int i = 1; i <= exp; i++)
        result *= base;
    return result;
}
int fromBinaryToDecimal(const char num[MAX], const int n) {
    int result = 0;
    for (int i = n - 1; i >= 0; i--)
        result += (num[i] - '0') * pow(2, i);
    return result;
}
void fromDecimalToBinary(char num[MAX], unsigned number, int& counter) {
    while (number) {
        num[counter++] = number % 2 + '0';
        number /= 2;
    }
}
int main() {
    int num, pos, counter = 0;
    cin >> num >> pos;
    char number[MAX];
    fromDecimalToBinary(number, num, counter);
    for (int i = 0; i < counter; i++)
        if (i == pos)
            {number[i] = number[i] == '1' ? '0' : '1';}
    cout << fromBinaryToDecimal(number, counter);
}