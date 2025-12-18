#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// this function returns a part of a string, starting from index start to the next len amount of symbols
char* createSubstring(const char str[], size_t start, size_t len) {
    char* word = new char[len + 1];
    for (size_t i = 0; i < len; ++i) {
        word[i] = str[start + i];
    }
    word[len] = '\0';
    return word;
}

bool isWhitespace(char c) {
    return c == ' ' || c == '\t';
}

char* getNthWord(const char str[], int n) {
    if (!str || n <= 0) {
        return nullptr;
    }

    int wordCount = 0;
    size_t i = 0;

    while (str[i] != '\0') {
        if (isWhitespace(str[i])) {
            i++;
            continue; // skip whitespaces
        }

        // beginning of new word
        ++wordCount;

        if (wordCount == n) {
            size_t start = i;
            // loop until the next first whitespace encounter
            while (str[i] != '\0' && !isWhitespace(str[i])) {
                i++;
            }
            return createSubstring(str, start, i - start);
        }

        // skip rest of the word
        while (str[i] != '\0' && !isWhitespace(str[i])) {
            ++i;
        }
    }

    return nullptr;
}

int main() {
    char buff[1024];
    cin.getline(buff, 1024);

    int n;
    cin >> n;

    char* word = getNthWord(buff, n);
    if (word) {
        cout << word;
        delete[] word;
    } else {
        cout << "Not enough words!";
    }
}
