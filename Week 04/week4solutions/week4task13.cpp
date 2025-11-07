#include <iostream>
using namespace std;

int sumOfPrimeNumbers(int n) {
    int sum = 0;
    for (int j = 1; j <= n; j++)
    {
        int x = 0;
        for (int i = 1; i <= n; i++)
        {
            if (j % i == 0) { x++; }
        }
        if (x == 2) { sum += j; }
    }
    return sum;
}
int main()
{
    int a;
    cin >> a;
    cout << sumOfPrimeNumbers(a);
}