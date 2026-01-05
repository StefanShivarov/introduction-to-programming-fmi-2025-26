#include <iostream>
using std::cin;
using std::cout;
using std::endl;

unsigned getLengthOfString(const char* str) {
    unsigned len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

unsigned getFirstWordStartingIndex(const char* str) {
    unsigned index = 0;
    while (str[index] != '\0') {
        if (str[index] != ' ' && str[index] != '\t') {
            return index;
        }
        index++;
    }
    return index;
}

unsigned getLastWordStartingIndex(const char* str) {
    unsigned len = getLengthOfString(str);
    if (len == 0) {
        return 0;
    }

    int i = len - 1;
    while (i >= 0 && (str[i] == ' ' || str[i] == '\t')) {
        i--;
    }

    while (i >= 0 && str[i] != ' ' && str[i] != '\t') {
        i--;
    }

    return i + 1;
}

unsigned getWordLength(const char* str, unsigned startIndex) {
    unsigned len = 0;
    while (str[startIndex + len] != '\0' && str[startIndex + len] != ' ' && str[startIndex + len] != '\t') {
        len++;
    }
    return len;
}

char* concatFirstAndLastWordWithSpaceBetween(const char* str) {
    unsigned firstStart = getFirstWordStartingIndex(str);
    unsigned lastStart = getLastWordStartingIndex(str);

    unsigned firstLen = getWordLength(str, firstStart);
    unsigned lastLen  = getWordLength(str, lastStart);

    char* result = new char[firstLen + lastLen + 2];

    unsigned pos = 0;
    for (unsigned i = 0; i < firstLen; i++) {
        result[pos++] = str[firstStart + i];
    }

    result[pos++] = ' ';

    for (unsigned i = 0; i < lastLen; i++) {
        result[pos++] = str[lastStart + i];
    }

    result[pos] = '\0';
    return result;
}

int main() {
    char buff[1024];
    cin.getline(buff, 1024);

    char* result = concatFirstAndLastWordWithSpaceBetween(buff);
    cout << result << endl;

    delete[] result;
}
