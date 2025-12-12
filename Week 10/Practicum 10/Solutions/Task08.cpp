#include <iostream>
using namespace std;

unsigned getLengthOfString(const char* str) {
    unsigned length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

bool isPalindrome(const char s[]) {
    unsigned length = getLengthOfString(s);
    for (int i = 0; i < length / 2; i++) {
        if (s[i] != s[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char s[256];
    cin.getline(s, 256);

    cout << isPalindrome(s) << endl;

    return 0;
}
