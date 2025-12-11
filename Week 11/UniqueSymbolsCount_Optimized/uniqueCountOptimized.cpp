#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// this solution uses 8 times less memory than the previous one
int analyzeStr(const char *str) {
    if (str == nullptr) {
        return -1;
    }

    // instead of using a bool array of 256 elements,
    // we can store the same information in only 32 bytes,
    // which is 8 times less memory

    unsigned char seen[32] {0}; // 32 * 8 = 256 bits, a bit for every symbol
    int uniqueSymbolsCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        int byteIndex = str[i] / 8;
        int bitIndex = str[i] % 8;
        unsigned char mask = (1 << bitIndex);

        if (!(seen[byteIndex] & mask)) {
            seen[byteIndex] |= mask;
            uniqueSymbolsCount++;
        }
    }

    return uniqueSymbolsCount;
}

int main() {
    char buff[1024];
    cin.getline(buff, 1024);
    cout << analyzeStr(buff) << endl;
}
