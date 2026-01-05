#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_LENGTH = 1024;

unsigned getLengthOfString(const char* str) {
    unsigned len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

char* createReversed(const char* str) {
    unsigned len = getLengthOfString(str);
    char* result = new char[len + 1];
    for (unsigned i = 0; i < len; i++) {
        result[i] = str[len - 1 - i];
    }
    return result;
}

int main() {
    char str[MAX_LENGTH];
    cin.getline(str, MAX_LENGTH);
    char* reversed = createReversed(str);
    cout << reversed << endl;
    delete[] reversed;
}
