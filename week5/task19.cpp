#include <iostream>
using namespace std;

int getDivision(int first, int second) {
    int counter = 0;
    while (first >= second) {
        first -= second;
        counter++;
    }
    return counter;
}
int main() {
    int first, second;
    cin >> first >> second;
    cout << getDivision(first, second) << endl;
}