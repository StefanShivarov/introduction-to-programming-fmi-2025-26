#include <iostream>
using namespace std;

constexpr int MAX = 100;
size_t strlen(const char str[]) {
    int length = 0;
    while (str[length++] != '\0');
    return length - 1;
}
bool isPalindrome(char str[]) {
    for (int i = 0; i < strlen(str) / 2; i++)
        if (str[i] != str[strlen(str) - 1 - i])
            return false;
    return true;
}
int main() {
    char str[MAX];
    cin >> str;
    if (isPalindrome(str))
        cout << "Palindrome";
    else
        cout << "Not a palindrome";
}