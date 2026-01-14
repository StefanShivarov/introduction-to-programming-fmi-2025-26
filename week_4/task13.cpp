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
    int sum = 0;
    for (int i = 2; i < num; i++)
        if (!isPrime(i))
            sum += i;
    cout << sum;
}