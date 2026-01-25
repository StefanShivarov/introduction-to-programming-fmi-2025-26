#include <iostream>
using namespace std;

size_t strlen(const char *s) {
    size_t len = 0;
    while (s[len++]);
    return len - 1;
}
bool isPalindrome(const char* s, const int beg, const unsigned long end) {
    if (beg > end) {
        return true;
    }
    if (s[beg] != s[end]) {
        return false;
    }
    return isPalindrome(s, beg + 1, end - 1);
}
int main() {
    char str[1024];
    cin >> str;
    constexpr int beg = 0;
    const unsigned long end = strlen(str) - 1;
    const bool result = isPalindrome(str, beg, end);
    if (result) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}