#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
    }
    cout << sum;
}