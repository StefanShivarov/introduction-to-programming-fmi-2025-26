#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_LENGTH = 1024;

unsigned getLengthOfString(const char* str) {
    unsigned len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* concat(const char* s1, const char* s2) {
    unsigned len1 = getLengthOfString(s1);
    unsigned len2 = getLengthOfString(s2);

    char* result = new char[len1 + len2 + 1];
    for (unsigned i = 0; i < len1; i++) {
        result[i] = s1[i];
    }
    for (unsigned i = 0; i < len2; i++) {
        result[len1 + i] = s2[i];
    }
    result[len1 + len2] = '\0';
    return result;
}

int main() {
    char s1[MAX_LENGTH];
    cin.getline(s1, MAX_LENGTH);

    char s2[MAX_LENGTH];
    cin.getline(s2, MAX_LENGTH);

    char* str = concat(s1, s2);
    cout << str << endl;
    delete[] str;
}
