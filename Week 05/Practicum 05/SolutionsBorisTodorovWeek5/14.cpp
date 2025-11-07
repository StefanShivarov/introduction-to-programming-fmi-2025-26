#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int getLength(int number)
{
    int temp = number;
    int length = 0;
    while (temp >= 1)
    {
        length++;
        temp /= 10;
    }
    return length;
}
void swapNumbers(int& n, int& m, int k)
{
    int nTemp = n;
    int mTemp = m;
    int nDigit = 0;
    int mDigit = 0;
    int nLength = getLength(n);
    int mLength = getLength(m);
    int nDivider = 1;
    int mDivider = 1;
    for (int i = 0;i < nLength - k;i++)
    {
        nDivider *= 10;
    }
    for (int i = 0;i < mLength - k;i++)
    {
        mDivider *= 10;
    }
    nTemp /= nDivider;
    mTemp /= mDivider;
    nDigit = nTemp % 10;
    mDigit = mTemp % 10;
    n = n - nDigit * nDivider + mDigit * nDivider;
    m = m - mDigit * mDivider + nDigit * mDivider;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    swapNumbers(n, m, k);
    cout << n << " , " << m;
}
