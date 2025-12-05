#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int analyzeArr(const char *str) {
    if (str == nullptr) {
        return -1;
    }

    bool seen[256] { false };
    int uniqueSymbolsCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char currentSymbol = str[i];

        // when passed as index, currentSymbol will be converted to the ASCII-value of the symbol (a number between 0 and 255)
        if (!seen[currentSymbol]) {
            seen[currentSymbol] = true;
            uniqueSymbolsCount++;
        }
    }

    return uniqueSymbolsCount;
}

int main() {
    char buff[1024];
    cin.getline(buff, 1024);
    cout << analyzeArr(buff) << endl;
}
