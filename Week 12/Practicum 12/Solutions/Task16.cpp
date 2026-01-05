#include <iostream>
using std::cin;
using std::cout;
using std::endl;

unsigned getLengthOfString(const char* str) {
    unsigned len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

char* insertSymbolAtIndices(char symbol, const char* str, int* indices, unsigned indicesCount) {
    selectionSort(indices, indicesCount);

    unsigned len = getLengthOfString(str);
    char* result = new char[len + indicesCount + 1];

    unsigned strPos = 0;
    unsigned resPos = 0;
    unsigned idxPos = 0;

    while (strPos < len) {
        if (idxPos < indicesCount && strPos == (unsigned)indices[idxPos]) {
            result[resPos++] = symbol;
            idxPos++;
        }

        result[resPos++] = str[strPos++];
    }

    result[resPos] = '\0';
    return result;
}

int main() {
    char buff[1024];
    cin.getline(buff, 1024);

    unsigned indicesCount;
    cin >> indicesCount;

    int* indices = new int[indicesCount];
    for (unsigned i = 0; i < indicesCount; i++) {
        cin >> indices[i];
    }

    char symbol;
    cin >> symbol;

    char* result = insertSymbolAtIndices(symbol, buff, indices, indicesCount);
    cout << result << endl;

    delete[] result;
    delete[] indices;
}
