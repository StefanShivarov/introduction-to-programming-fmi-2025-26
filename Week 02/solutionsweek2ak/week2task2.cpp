#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int n1;
    cin >> n1;
    int max = 0;
    int b;
    for (int i = 0; i < n1; i++)
    {
        cin >> b;
        if (b > max) { max = b; }
    }
    cout << max;
}