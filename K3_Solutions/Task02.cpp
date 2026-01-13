#include <iostream>
using std::cin;
using std::cout;

const int REMAINDERS_BYTES_COUNT = 2; // 2 bytes needed to store remainders
const int DIGITS_BYTES_COUNT = 2; // 2 bytes needed to store 9 bits
const int TWO_DIGIT_NUMS_COUNT = 90;
const int TWO_DIGIT_NUMS_BYTES_COUNT = 12; // 12 bytes needed to store 90 bits
                                           //(one bit for every two-digit number)

bool checkBit(const unsigned char* bytes, int bytesCount, int pos) {
    if (bytes == nullptr) {
        return false;
    }
    int byteIndex = pos / 8;
    if (byteIndex >= bytesCount) {
        return false;
    }
    unsigned char mask = 1 << (pos % 8);
    return bytes[pos / 8] & mask;
}

void setBitToOneAtPos(unsigned char* bytes, int bytesCount, int pos) {
    if (bytes == nullptr) {
        return;
    }
    int byteIndex = pos / 8;
    if (byteIndex >= bytesCount) {
        return;
    }
    unsigned char mask = 1 << (pos % 8);
    bytes[pos / 8] |= mask;
}

bool isTwoDigitNumber(int num) {
    return num >= 10 && num <= 99;
}

void extractDigits(int num, unsigned char* digitsBytes) {
    if (digitsBytes == nullptr) {
        return;
    }
    if (num == 0) {
        setBitToOneAtPos(digitsBytes, DIGITS_BYTES_COUNT, 0);
        return;
    }
    while (num) {
        setBitToOneAtPos(digitsBytes, DIGITS_BYTES_COUNT, num % 10);
        num /= 10;
    }
}

void printUniqueRemainders(int n, int k) {
    unsigned char digitsBytes[DIGITS_BYTES_COUNT] {0};
    extractDigits(n, digitsBytes);

    unsigned char remaindersBytes[REMAINDERS_BYTES_COUNT] {0};
    for (int tens = 1; tens <= 9; tens++) {
        if (!checkBit(digitsBytes, DIGITS_BYTES_COUNT, tens)) {
            continue;
        }

        for (int units = 0; units <= 9; units++) {
            if (units == tens || !checkBit(digitsBytes, DIGITS_BYTES_COUNT, units)) {
                continue;
            }

            int twoDigitNumber = tens * 10 + units;
            int remainder = twoDigitNumber % k;
            if (remainder != 0) {
                setBitToOneAtPos(remaindersBytes, REMAINDERS_BYTES_COUNT, remainder);
            }
        }
    }

    for (int i = 1; i < k; i++) {
        if (checkBit(remaindersBytes, REMAINDERS_BYTES_COUNT, i)) {
            cout << i << ' ';
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    if (n < 10 || (k < 2 || k > 9)) {
        cout << "Invalid input\n";
        return 1;
    }
    printUniqueRemainders(n, k);
}
