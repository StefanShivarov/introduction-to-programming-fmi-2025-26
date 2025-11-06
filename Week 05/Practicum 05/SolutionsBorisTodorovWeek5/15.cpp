#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void changeNumbers(int& a, int& b, int k)
{
    int numToAdd = 0;
    int divider = 1;
    for (int i = 0;i < k;i++)
    {
        divider *= 10;
    }
    numToAdd = a % divider;
    a /= divider;
    b = b  + numToAdd*divider;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    changeNumbers(n, m, k);
    cout << n << " , " << m;
}
