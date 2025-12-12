#include <iostream>
using namespace std;

int main() {
    int counter = 0;
    int temp = 0;
    int min = 0;
    while (counter < 3) {
        cin >> temp;
        if (temp < 0) {
            counter++;
            if (min > temp)
                min = temp;
        }
        else {
            counter = 0;
            min = 0;
        }
    }
    cout << min;
}