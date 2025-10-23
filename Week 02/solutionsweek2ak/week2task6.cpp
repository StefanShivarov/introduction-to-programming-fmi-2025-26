#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int n1;
    int k1;
    cin >> n1 >> k1;
    int sumk1 = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sumk1 += k1 * (pow(10, j));
        }
    }
    cout << sumk1;
}