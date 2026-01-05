#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_LENGTH = 1024;

bool isLowercaseLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isUppercaseLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

unsigned getCountByCriteria(const char* str, bool (*crit) (char c)) {
    unsigned count = 0, i = 0;
    while (str[i] != '\0') {
        if (crit(str[i])) {
            count++;
        }
        i++;
    }
    return count;
}

char* concatLowerUpper(const char* s1, const char* s2) {
    unsigned lowerCountS1 = getCountByCriteria(s1, isLowercaseLetter);
    unsigned upperCountS2 = getCountByCriteria(s2, isUppercaseLetter);

    char* result = new char[lowerCountS1 + upperCountS2 + 1];
    unsigned i = 0, count = 0;
    while (s1[i] != '\0') {
        if (isLowercaseLetter(s1[i])) {
            result[count] = s1[i];
            count++;
        }
        i++;
    }
    i = 0, count = 0;
    while (s2[i] != '\0') {
        if (isUppercaseLetter(s2[i])) {
            result[lowerCountS1 + count] = s2[i];
            count++;
        }
        i++;
    }
    result[lowerCountS1 + upperCountS2] = '\0';
    return result;
}

int main() {
    char s1[MAX_LENGTH];
    cin.getline(s1, MAX_LENGTH);
    char s2[MAX_LENGTH];
    cin.getline(s2, MAX_LENGTH);

    char* str = concatLowerUpper(s1, s2);
    cout << str << endl;
    delete[] str;
}
