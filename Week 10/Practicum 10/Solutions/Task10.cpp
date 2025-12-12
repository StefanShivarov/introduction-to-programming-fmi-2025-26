#include <iostream>
using namespace std;

unsigned myStrlen(const char* str) {
    unsigned length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void substring(const char src[], char dest[], int beg, int end) {
    unsigned len = myStrlen(src);

    if (beg >= len) {
        dest[0] = '\0';
        return;
    }

    if (end >= len) {
        end = len - 1;
    }

    int index = 0;
    for (int i = beg; i <= end; i++) {
        dest[index++] = src[i];
    }
    dest[index] = '\0';
}

int main() {
    char s[256];
    char sub[256];

    cin >> s;

    int beg, end;
    cin >> beg >> end;

    substring(s, sub, beg, end);

    cout << sub;
}
