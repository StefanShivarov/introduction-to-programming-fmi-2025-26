#include <iostream>
using namespace std;

bool isCapitalLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

// unsigned myStrlen(const char* str) {
//     unsigned counter = 0;
//     while (str[counter] != '\0') {
//         counter++;
//     }
//     return counter;
// }

void reverseStr(char* str, unsigned length)
{
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

long myPow(int x, unsigned n)
{
    long long pow = 1;

    for (int i = 0; i < n; i++) {
        pow = pow * x;
    }

    return pow;
}

void decimalToKth(int num, int k, char* digits, unsigned digitsCount) {
    int index = 0;
    while (num) {
        int remainder = num % k;
        if (remainder > 9) {
            digits[index++] = (remainder - 10) + 'A';
        } else {
            digits[index++] = num % k + '0';
        }
        num /= k;
    }
    digits[index] = '\0';
    reverseStr(digits, digitsCount);
}

long kthToDecimal(int k, const char* digits, unsigned digitsCount) {
    int deg = 0, result = 0;
    for (int i = digitsCount - 1; i >= 0; i--) {
        if (isCapitalLetter(digits[i])) {
            result += (digits[i] - 'A' + 10) * myPow(k, deg);
        } else {
            result += (digits[i] - '0') * myPow(k, deg);
        }
        deg++;
    }
    return result;
}

int main() {
    // this time i am using n, so we dont need myStrlen, both ways work
    int n, k;
    cin >> n >> k;

    char first[20];
    cin >> first;
    int firstDecimal = kthToDecimal(k, first, n);

    cin >> n >> k;
    char second[20];
    cin >> second;
    int secondDecimal = kthToDecimal(k, second, n);

    cout << (firstDecimal == secondDecimal);
}