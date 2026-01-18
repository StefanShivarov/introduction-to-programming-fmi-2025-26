#include <iostream>
using namespace std;

int concat(unsigned int first, unsigned int second) {
    int copyOfSecond = second;
    int counter = 0;
    while (copyOfSecond > 0) {
        copyOfSecond /= 10;
        counter++;
    }
    for (int i = 0; i < counter; i++)
        first *= 10;
    return first + second;
}
int main() {
    cout << "Въведете 2 числа: ";
    int a, b;
    cin >> a >> b;
    cout << concat(a, b);
}