#include <iostream>
using namespace std;

void extractLowercase(const char* src, char* dest) {
    int index = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] >= 'a' && src[i] <= 'z') {
            dest[index++] = src[i];
        }
    }
    dest[index] = '\0';
}

int main() {
    char s1[256];
    char s2[256];

    cin >> s1;
    extractLowercase(s1, s2);
    cout << s2;
}
