#include <iostream>
using namespace std;

const unsigned MAX_SIZE = 50;

void readArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

long power(unsigned num, unsigned pow) {
    long result = 1;
    for (unsigned i = 0; i < pow; i++) {
        result *= num;
    }
    return result;
}

unsigned getLengthOfString(const char* str) {
    unsigned length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void reverseStr(char* str) {
    unsigned strLength = getLengthOfString(str);
    for (unsigned i = 0; i < strLength / 2; i++) {
        swap(str[i], str[strLength - 1 - i]);
    }
}

char decimalToChar(unsigned number) {
    if (0 <= number && number <= 9) {
        return number + '0';
    }
    if (10 <= number && number < 35) {
        return (number - 10) + 'A';
    }
    return 0;
}

unsigned charToDecimal(char symbol) {
    if ('0' <= symbol && symbol <= '9') {
        return symbol - '0';
    }
    if ('A' <= symbol && symbol <= 'Z') {
        return symbol - 'A' + 10;
    }
    return 0;
}

void convertDecimalToAnyBase(unsigned decimal, unsigned k, char* result) {
    unsigned resultLength = 0;
    while (decimal != 0) {
        unsigned lastDigit = decimal % k;
        result[resultLength++] = decimalToChar(lastDigit);
        decimal /= k;
    }
    result[resultLength] = '\0';
    reverseStr(result);
}

long convertFromAnyBaseToDecimal(const char* digits, unsigned k) {
    long result = 0;
    unsigned powCounter = 0;
    unsigned digitsLength = getLengthOfString(digits);
    for (int i = digitsLength - 1; i >= 0; i--) {
        result += charToDecimal(digits[i]) * power(k, powCounter);
        powCounter++;
    }
    return result;
}

void convertFromNthToKthBase(const char* fromNumber, unsigned n, char* result, unsigned k) {
    long decimal = convertFromAnyBaseToDecimal(fromNumber, n);
    convertDecimalToAnyBase(decimal, k, result);
}

int main() {
    unsigned fromBase, toBase;
    cin >> fromBase >> toBase;

    char str[MAX_SIZE];
    cin >> str;

    char result[MAX_SIZE];
    convertFromNthToKthBase(str, fromBase, result, toBase);

    cout << result;
}
