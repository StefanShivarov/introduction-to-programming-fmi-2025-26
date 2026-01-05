#include <iostream>
using std::cin;
using std::cout;
using std::endl;

unsigned countUnique(const char* str) {
    unsigned bytes[8] = {0};
    unsigned count = 0;

    for (unsigned i = 0; str[i] != '\0'; i++) {
        unsigned c = str[i];
        unsigned byteIndex = c / 32;
        unsigned bitPos = c % 32;

        if (!(bytes[byteIndex] & (1 << bitPos))) {
            bytes[byteIndex] |= (1 << bitPos);
            count++;
        }
    }

    return count;
}

char* removeDuplicates(const char* str) {
    unsigned size = countUnique(str);
    char* result = new char[size + 1];

    unsigned bytes[8] = {0};
    unsigned index = 0;

    for (unsigned i = 0; str[i] != '\0'; i++) {
        unsigned c = str[i];
        unsigned byteIndex = c / 32;
        unsigned bitPos = c % 32;

        if (!(bytes[byteIndex] & (1 << bitPos))) {
            bytes[byteIndex] |= (1 << bitPos);
            result[index++] = str[i];
        }
    }

    result[index] = '\0';
    return result;
}



int main() {
    char buff[1024];
    cin.getline(buff, 1024);
    char* result = removeDuplicates(buff);
    cout << result << endl;
    delete[] result;
}
