#include <iostream>
using std::cin;
using std::cout;

const int ASCII_UPPERCASE_LOWERCASE_DIFF = 32;

bool isUppercaseLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLowercaseLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

int getLengthOfString(const char* str) {
    if (str == nullptr) {
        return 0;
    }
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void reverseSubstring(char* str, int from, int to) {
    if (str == nullptr || from >= to) {
        return;
    }

    while (from < to) {
        swap(str[from], str[to]);
        from++;
        to--;
    }
}

void splitInReversedGroups(char* str, int k) {
    int len = getLengthOfString(str);
    int groupStart = 0;
    while (groupStart < len) {
        int groupEnd = min(groupStart + k, len) - 1;
        reverseSubstring(str, groupStart, groupEnd);
        groupStart += k;
    }
}

void replaceCharacters(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isLowercaseLetter(str[i]) || str[i] == '?') {
            continue;
        }

        if (isUppercaseLetter(str[i])) {
            str[i] += ASCII_UPPERCASE_LOWERCASE_DIFF;
        } else if (isDigit(str[i])) {
            str[i] = '0' + (9 - (str[i] - '0'));
        } else {
            str[i] = '*';
        }
    }
}

void transformString(char* str, int k) {
    splitInReversedGroups(str, k);
    replaceCharacters(str);
}

int main() {
    char buff[1024];
    cin >> buff; // or cin.getline(buff, 1024) if you want to read whitespaces too;
    transformString(buff, 3);
    cout << buff;
}
