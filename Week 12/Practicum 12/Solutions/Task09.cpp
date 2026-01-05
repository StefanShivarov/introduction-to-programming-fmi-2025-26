#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool isLetter(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

unsigned getResultLength(const int* first, const int* second, unsigned size) {
    unsigned count = 0;
    for (unsigned i = 0; i < size; i++) {
        if (isLetter(first[i] + second[i])) {
            count++;
        }
    }
    return count;
}

char* getLettersOfSums(const int* first, const int* second, unsigned size) {
    unsigned len = getResultLength(first, second, size);
    char* result = new char[len + 1];
    unsigned index = 0;
    for (unsigned i = 0; i < size; i++) {
        if (isLetter(first[i] + second[i])) {
            result[index++] = first[i] + second[i];
        }
    }
    result[len] = '\0';
    return result;
}

int main() {
    unsigned n;
    cin >> n;

    int* first = new int[n];
    for (unsigned i = 0; i < n; i++) {
        cin >> first[i];
    }

    int* second = new int[n];
    for (unsigned i = 0; i < n; i++) {
        cin >> second[i];
    }

    char* letters = getLettersOfSums(first, second, n);
    cout << letters << endl;

    delete[] letters;
    delete[] first;
    delete[] second;
}
