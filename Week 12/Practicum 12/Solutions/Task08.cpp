#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int getSpaceIndex(const char* str) {
    unsigned i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            return i;
        }
        i++;
    }
    return -1;
}

unsigned getLengthOfString(const char* str) {
    unsigned len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* getStrWithReplacedChars(const char* str, const char* pattern) {
    int spaceIndex = getSpaceIndex(pattern);
    if (spaceIndex == -1) {
        cout << "No space in pattern!";
        return nullptr;
    }

    char replacements[256];
    for (int i = 0; i < 256; i++) {
        replacements[i] = (char)i;
    }

    for (int i = 0; i < spaceIndex; i++) {
        replacements[pattern[i]] = (char)pattern[spaceIndex + 1 + i];
    }

    unsigned len = getLengthOfString(str);
    char* result = new char[len + 1];
    for (unsigned i = 0; i < len; i++) {
        result[i] = replacements[str[i]];
    }

    result[len] = '\0';
    return result;
}

int main() {
    char str[1024];
    cin.getline(str, 1024);

    char pattern[1024];
    cin.getline(pattern, 1024);

    char* result = getStrWithReplacedChars(str, pattern);
    if (result == nullptr) {
        cout << "No space in pattern!";
        return 1;
    }

    cout << result << endl;
    delete[] result;
}
