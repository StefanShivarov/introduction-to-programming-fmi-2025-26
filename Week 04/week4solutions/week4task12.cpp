#include <iostream>
using namespace std;

bool isPrime(int n) {
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0) { x++; }
    }
    if (x == 2) { return true; }
    else { return false; }
}
int main()
{
    int a;
    cin >> a;
    if (isPrime(a)) { cout << "The number is prime."; }
    else { cout << "The number is not prime."; }
}