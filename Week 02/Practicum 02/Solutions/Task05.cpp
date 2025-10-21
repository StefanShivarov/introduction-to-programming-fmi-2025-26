#include <iostream>

using namespace std;

const unsigned int MAX_COUNT_OF_NEGATIVES = 3;

int main() {
    unsigned int countOfNegatives = 0;
    int smallestNum = 0;

    while (countOfNegatives < MAX_COUNT_OF_NEGATIVES) {
        int num = 0;
        cin >> num;

        if (num < 0) {
            ++countOfNegatives;
            if (num < smallestNum) { smallestNum = num; }
        } else {
            countOfNegatives = 0;
            smallestNum = 0;
        }
    }

    cout << "The smallest num is: " << smallestNum << endl;

    return 0;
}