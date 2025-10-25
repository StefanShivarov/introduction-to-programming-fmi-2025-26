#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool isPrime(int n)
{
    for (int i = 2;i < n;i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int sum = 0;
    int n;
    cin >> n;
    for (int i = 2;i < n;i++)
    {
        if (isPrime(i))
        {
            sum += i;
        }
    }
    cout << sum;
}
