#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int n;
    int k;
    int kTemp = 0;
    int sum = 0;
    cin >> n >> k;
    for (int i = 0;i < n;i++)
    {
        kTemp = k;
        for (int j = 0;j < i;j++)
        {
            kTemp = kTemp * 10 + k;
        }
        sum += kTemp;
    }
    cout << sum;
}