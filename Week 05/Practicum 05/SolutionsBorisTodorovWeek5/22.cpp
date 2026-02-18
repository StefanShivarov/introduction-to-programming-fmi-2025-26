#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void factorization(int n)
{
    int nTemp = n;
    for (int i = 2; i < nTemp;i++)
    {
        if (n % i == 0)
        {
            n /= i;
            if (n == 1)
            {
                cout << i;
                return;
            }
            else
            {
                cout << i << ".";
            }
            i--;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    factorization(n);
}
