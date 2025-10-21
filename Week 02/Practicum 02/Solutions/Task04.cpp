#include <iostream>

using namespace std;

const unsigned int MAX_COUNT_OF_POSITIVES = 5;

int main() {
    unsigned int countOfPositives = 0, sumOfPositives = 0;

    while (countOfPositives < MAX_COUNT_OF_POSITIVES) {
        int num = 0;
        cin >> num;

        if (num > 0) { 
            ++countOfPositives; 
            sumOfPositives += num;
        }
    }

    cout << "The sum is: " << sumOfPositives << endl;

    return 0;
}