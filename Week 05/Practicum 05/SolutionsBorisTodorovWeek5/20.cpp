#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int closestPowerOfTwo(int n)
{
    int numAbove = 1;
    int numUnder = 1;
    while (numAbove < n)
    {
        numAbove *= 2;
    }
    numUnder = numAbove / 2;
    if (numAbove - n < n - numUnder)
    {
        return numAbove;
    }
    else
    {
        return numUnder;
    }
}
int main()
{
    int n = 0;
    cin >> n;
    cout << closestPowerOfTwo(n);
}