#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int n;
    cin >> n;
    int factoriel = 1;
    for (int i = 1;i < n+1;i++)
    {
        factoriel *= i;
    }
    cout << factoriel;
}