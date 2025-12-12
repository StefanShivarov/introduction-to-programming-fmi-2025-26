#include <iostream>
using namespace std;

bool isWordBoundary(char c) {
    return c == ' ' || c == '\0' || c == '.' || c == ',' || c == '!' || c == '?';
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}

void censor(char text[], const char word[]) {
    int wordLength = 0;
    while (word[wordLength] != '\0') {
        wordLength++;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (i == 0 || isWordBoundary(text[i - 1])) {
            int textIndex = i;
            int wordIndex = 0;

            while (word[wordIndex] != '\0' && text[textIndex] != '\0' &&
                   toLower(text[textIndex]) == toLower(word[wordIndex])) {
                wordIndex++;
                textIndex++;
                   }

            if (wordIndex == wordLength && isWordBoundary(text[textIndex])) {
                for (int replaceIndex = i; replaceIndex < i + wordLength; replaceIndex++) {
                    text[replaceIndex] = '*';
                }
                i = textIndex - 1;
            }
        }
    }
}

int main() {
    char text[256];
    char word[256];

    cin.getline(text, 256);
    cin.getline(word, 256);

    censor(text, word);

    cout << text;
}
