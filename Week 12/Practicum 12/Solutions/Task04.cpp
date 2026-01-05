#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool contains(const int* arr, unsigned size, int value) {
    for (unsigned i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

unsigned countUniqueDivisibleByK(const int* first, unsigned firstSize,
                                 const int* second, unsigned secondSize,
                                 unsigned k) {
    int* temp = new int[firstSize + secondSize];
    unsigned tempSize = 0;

    for (unsigned i = 0; i < firstSize; i++) {
        if (first[i] % k == 0 && !contains(temp, tempSize, first[i])) {
            temp[tempSize++] = first[i];
        }
    }

    for (unsigned i = 0; i < secondSize; i++) {
        if (second[i] % k == 0 && !contains(temp, tempSize, second[i])) {
            temp[tempSize++] = second[i];
        }
    }

    delete[] temp;
    return tempSize;
}

int* getArrWithDivisibleByK(const int* first, unsigned firstSize,
                            const int* second, unsigned secondSize,
                            unsigned k, unsigned& resultSize) {
    resultSize = countUniqueDivisibleByK(first, firstSize, second, secondSize, k);
    int* result = new int[resultSize];

    unsigned pos = 0;

    for (unsigned i = 0; i < firstSize; i++) {
        if (first[i] % k == 0 && !contains(result, pos, first[i])) {
            result[pos++] = first[i];
        }
    }

    for (unsigned i = 0; i < secondSize; i++) {
        if (second[i] % k == 0 && !contains(result, pos, second[i])) {
            result[pos++] = second[i];
        }
    }

    return result;
}

int main() {
    unsigned firstSize, secondSize;
    cin >> firstSize;

    int* first = new int[firstSize];
    for (unsigned i = 0; i < firstSize; i++) {
        cin >> first[i];
    }

    cin >> secondSize;
    int* second = new int[secondSize];
    for (unsigned i = 0; i < secondSize; i++) {
        cin >> second[i];
    }

    unsigned k;
    cin >> k;

    // assume k != 0
    unsigned resultSize;
    int* result = getArrWithDivisibleByK(first, firstSize, second, secondSize, k, resultSize);

    for (unsigned i = 0; i < resultSize; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;

    delete[] result;
    delete[] first;
    delete[] second;
}
