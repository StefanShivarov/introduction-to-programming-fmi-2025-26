#include <iostream>
using namespace std;

int numLength(unsigned int n) {
    int counter = 0;
    while (n) {
        n /= 10;
        counter++;
    }
    return counter;
}
void sortDigits(unsigned int& number) {
    unsigned int numCopy = number;
    unsigned int sortedNum = 0;
    for (int i = 0; i <= 9; i++) {
        numCopy = number;
        for (int j = 0; j < numLength(number); j++) {
            if (i == numCopy % 10)
                sortedNum = sortedNum * 10 + numCopy % 10;
            numCopy /= 10;
        }
    }
    number = sortedNum;
}
int main() {
    unsigned int n;
    cin >> n;
    sortDigits(n);
    cout << n << endl;
}