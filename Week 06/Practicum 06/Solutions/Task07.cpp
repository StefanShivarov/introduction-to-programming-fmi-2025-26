#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_SIZE = 50;

double absoluteValue(double n) {
    return n < 0 ? -n : n;
}

const double EPSILON = 1e-12;
bool areEqual(double a, double b) {
    return absoluteValue(a - b) < EPSILON;
}

void readArray(int* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool hasZeroVector(const int* first, const int* second, unsigned size) {
    bool isFirstZero = true, isSecondZero = true;
    for (unsigned i = 0; i < size; i++) {
        if (first[i] != 0) {
            isFirstZero = false;
        }
        if (second[i] != 0) {
            isSecondZero = false;
        }
    }
    return isFirstZero || isSecondZero;
}

bool areLinearlyDependent(const int* first, const int* second, unsigned size) {
    if (hasZeroVector(first, second, size)) {
        return true;
    }

    // Find the first index where both are non-zero
    int nonZeroIndex = -1;
    for (unsigned i = 0; i < size; i++) {
        if (first[i] != 0 && second[i] != 0) {
            nonZeroIndex = i;
            break;
        }

        if (first[i] != 0 && second[i] == 0) {
            return false;
        }
        if (first[i] == 0 && second[i] != 0) {
            return false;
        }
    }

    if (nonZeroIndex == -1) {
        // All pairs were (0,0), impossible because zero-vector is already handled.
        return true;
    }

    double coefficient = (double)first[nonZeroIndex] / (double)second[nonZeroIndex];

    for (unsigned i = 0; i < size; i++) {
        if (first[i] == 0 && second[i] == 0) {
            continue;
        }

        if (second[i] == 0) {
            return false;
        }

        if (!areEqual(second[i] * coefficient, first[i])) {
            return false;
        }
    }

    return true;
}


int main() {
    unsigned n;
    cin >> n;
    int first[MAX_SIZE];
    int second[MAX_SIZE];
    readArray(first, n);
    readArray(second, n);

    cout << (areLinearlyDependent(first, second, n) ?
            "Yes, the arrays are linearly dependent."
            : "No, the arrays are not linearly dependent.") << endl;
}
