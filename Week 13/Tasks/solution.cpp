#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

const unsigned MAX_INPUT_LENGTH = 1024;

bool isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int getDigitsCount(int x) {
    if (x == 0) {
        return 1;
    }

    int count = 0;
    while (x > 0) {
        count++;
        x /= 10;
    }

    return count;
}

char* compressAndSort(const char* str) {
    // we can use this array to store the count for each symbol
    int countMap[256] = {0};

    // we fill the counts first
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isWhitespace(str[i])) {
            countMap[str[i]]++;
        }
    }

    // then we calculate the length of the result string
    int len = 0;
    for (int c = 0; c < 256; c++) {
        if (countMap[c] > 0) {
            len += 1 + getDigitsCount(countMap[c]); // for every symbol is 1 symbol + the digits count of its count
        }
    }

    // allocate dynamic memory
    char* result = new char[len + 1];
    int index = 0;
    for (int asciiValue = 0; asciiValue < 256; asciiValue++) {
        if (countMap[asciiValue] > 0) {
            result[index++] = (char)asciiValue; // get the symbol for the corresponding ascii value

            int count = countMap[asciiValue];
            int digitsCount = getDigitsCount(count);
            for (int j = digitsCount - 1; j >= 0; j--) {
                char lastDigitSymbol = '0' + (count % 10); // converting the digit to its corresponding symbol , ex: 1 -> '1'
                result[index + j] = lastDigitSymbol;
                count /= 10;
            }
            index += digitsCount;
        }
    }

    result[index] = '\0';
    return result;
}

int main() {
    char buff[MAX_INPUT_LENGTH];
    cin.getline(buff, MAX_INPUT_LENGTH);

    char* res = compressAndSort(buff);
    cout << res;

    delete[] res; // delete allocated dynamic memory!!!
}
