#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int powerOfTen(int x)
{
    int power = 1;
    for (int i = 0;i < x;i++)
    {
        power *= 10;
    }
    return power;
}

int sortNumber(int n)
{
    int nSorted = 0;
    int length = 0;
    int nTemp = n;
    int position = 0;
    int min = 0;
    while (nTemp > 0)
    {
        nTemp = nTemp / 10;
        length++;
    }
    nTemp = n;
    for (int i = 0;i < length;i++)
    {
        min = 9;
        for (int i = 0;i < length;i++)
        {
            if ((nTemp % 10 <= min) && (nTemp%10!=0))
            {
                min = nTemp % 10;
                position = i;
            }
            nTemp /= 10;
        }
        nSorted = nSorted * 10 + min;
        nTemp = n - min * (powerOfTen(position));
        n = nTemp;

    }
    return nSorted;
}
int main()
{
    int n;
    cin >> n;
    cout << sortNumber(n);
}
