#include <iostream>
using namespace std;

int main() {
    int counter = 0;
    int temp = 0;
    int sum = 0;
    while (counter < 5) {
        cin >> temp;
        if (temp > 0) {
            sum += temp;
            counter++;
        }
    }
    cout << sum << endl;
}