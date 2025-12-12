#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    a += b;
    b = a - b;
    a -= b;
}
size_t strlen(const char str[]) {
    int length = 0;
    while (str[length++] != '\0');
    return length - 1;
}
char lowerToUpperCase(const char ch) {
    return (char)(ch - 'a' + 'A');
}
char upperToLowerCase(const char ch) {
    return (char)(ch - 'A' + 'a');
}
char mod2(const char ch) {
    return (char)((ch - '0') % 2 + '0');
}
bool isLowerCase(const char ch) {
    return ch >= 'a' && ch <= 'z';
}
bool isUpperCase(const char ch) {
    return ch >= 'A' && ch <= 'Z';
}
bool isDigit(const char ch) {
    return ch >= '0' && ch <= '9';
}
void reverse(char str[]) {
    for (int i = 0; i < strlen(str) / 2; i++)
        swap(str[i], str[strlen(str) - 1 - i]);
}
void convertString(char str[], const char ch) {
    reverse(str);
    for (int i = 0; i < strlen(str); i++)
        if (isLowerCase(str[i]))
            str[i] = lowerToUpperCase(str[i]);
        else if (isUpperCase(str[i]))
            str[i] = upperToLowerCase(str[i]);
        else if (isDigit(str[i]))
            str[i] = mod2(str[i]);
        else
            str[i] = ch;
}
int main() {
    char str[1024];
    char ch;
    cin >> str >> ch;
    convertString(str, ch);
    cout << str;
}