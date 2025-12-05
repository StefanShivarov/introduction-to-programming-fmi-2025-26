#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

int getLengthOfString(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void reverseString(char* str) {
    int length = getLengthOfString(str);
    for (int i = 0; i < length / 2; i++) {
        swap(str[i], str[length - 1 - i]);
    }
}

bool isSmallLetter(char c) {
    return 'a' <= c && c <= 'z';
}

bool isCapitalLetter(char c) {
    return 'A' <= c && c <= 'Z';
}

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

const int ASCII_CASE_DIFFERENCE = 'a' - 'A';

void convertString(char* str, char ch) {
    int length = getLengthOfString(str);
    reverseString(str);

    for (int i = 0; i < length; i++) {
        if (isSmallLetter(str[i])) {
            str[i] -= ASCII_CASE_DIFFERENCE;
        } else if (isCapitalLetter(str[i])) {
            str[i] += ASCII_CASE_DIFFERENCE;
        } else if (isDigit(str[i])) {
            int digit = str[i] - '0';
            str[i] = char((digit % 2) + '0');
        } else {
            str[i] = ch;
        }
    }
}

int main() {
    char buff[1024];
    cin.getline(buff, 1024);
    convertString(buff, 'a');
    cout << buff << endl;
}
