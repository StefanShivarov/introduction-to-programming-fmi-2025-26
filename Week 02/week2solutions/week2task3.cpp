#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int c;
    cin >> c;
    int factoriel = 1;
    for (int i = 1; i < c + 1; i++)
    {
        factoriel *= i;
    }
    cout << factoriel;
}