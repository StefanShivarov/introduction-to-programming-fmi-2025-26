#include <iostream>
using std::cin;
using std::cout;
using std::endl;

unsigned getLongestCommonPrefixLength(const char* s1, const char* s2) {
    unsigned i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
           break;
        }
        i++;
    }
    return i;
}

char* getLongestCommonPrefix(const char* s1, const char* s2) {
    unsigned len = getLongestCommonPrefixLength(s1, s2);
    char* result = new char[len + 1];
    for (unsigned i = 0; i < len; i++) {
        result[i] = s1[i];
    }
    result[len] = '\0';
    return result;
}

int main() {
    char s1[1024];
    cin.getline(s1, 1024);
    char s2[1024];
    cin.getline(s2, 1024);
    char* result = getLongestCommonPrefix(s1, s2);
    cout << result << endl;
    delete[] result;
}
