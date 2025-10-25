#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int returnConcat(int n, int k)
{
    int length = 0;
    int kTemp = k;
    while (kTemp > 0)
    {
        kTemp = kTemp / 10;
        length++;
    }
    for (int i = 0;i < length;i++)
    {
        n = n * 10;
    }
    return n + k;
}
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    cout << returnConcat(n, k);
}
