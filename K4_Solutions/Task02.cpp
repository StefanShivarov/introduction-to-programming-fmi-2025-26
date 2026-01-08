#include <iostream>
#include <cstring>
using namespace std;

bool isSpace(char c) {
    return c == ' ' || c == '\t';
}

void reverseWord(const char* src, int len, char* dest, int& index) {
    for (int i = len - 1; i >= 0; i--) {
        dest[index++] = src[i];
    }
}

char* invertEvenWords(const char* str) {
    int len = 0;
    int n = strlen(str);
    bool firstWord = true;

    for (int i = 0; i < n;) {
        while (i < n && isSpace(str[i])) {
            i++;
        }
        int start = i;

        while (i < n && !isSpace(str[i])) {
            i++;
        }
        int wordLen = i - start;

        if (wordLen % 2 == 0 && wordLen > 0) {
            if (!firstWord) {
                len++;
            }
            len += wordLen;
            firstWord = false;
        }
    }

    char* result = new char[len + 1];
    int index = 0;

    firstWord = true;

    for (int i = 0; i < n;) {
        while (i < n && isSpace(str[i])) {
            i++;
        }
        int start = i;
        while (i < n && !isSpace(str[i])) {
            i++;
        }
        int wordLen = i - start;

        if (wordLen % 2 == 0 && wordLen > 0) {
            if (!firstWord) {
                result[index++] = ' ';
            }
            reverseWord(str + start, wordLen, result, index);
            firstWord = false;
        }
    }

    result[index] = '\0';
    return result;
}

int main() {
    char input[1024];
    cin.getline(input, 1024);

    char* res = invertEvenWords(input);
    cout << res << endl;

    delete[] res;
}
