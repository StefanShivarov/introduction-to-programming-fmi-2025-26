#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int a;
    int b;
    int c;
    int d;
    int sum = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    if (a % 2 == 0)
    {
        sum += a;
    }
    if (b % 2 == 0)
    {
        sum += b;
    }
    if (c % 2 == 0)
    {
        sum += c;
    }
    if (d % 2 == 0)
    {
        sum += d;
    }
    cout << sum;
}
