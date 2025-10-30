#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int returnDigitFromNum(int n, int k)
{
    int length = 0;
    int nTemp=n;
    while (nTemp > 0)
    {
        nTemp = nTemp / 10;
        length++;
    }
    for (int i = 0;i < length - k;i++)
    {
        n /= 10;
    }
    return n % 10;
}
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    cout << returnDigitFromNum(n, k);
}
