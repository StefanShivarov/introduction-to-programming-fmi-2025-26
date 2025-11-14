#include <iostream>
using namespace std;

bool isPrime(int num) {
    int counter = 0;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            counter++;
    return counter;
}
int main() {
    int num;
    cin >> num;
    if (!isPrime(num))
        cout << num << " е просто число";
    else
        cout << num << " не е просто число";
}