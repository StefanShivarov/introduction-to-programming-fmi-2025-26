#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool isPalindrome(int n)
{
    int length=0;
    int nTemp = n;
    int firsthalf = 0;
    int reversedFirsthalf = 0;
    int secondhalf = 0;
    int divider=1;
    while (nTemp > 0)
    {
        nTemp =nTemp/ 10;
        length++;
    }
    for (int i = 0;i < length / 2;i++)
    {
        divider *= 10;
    }
    secondhalf = n % divider;
    if (length % 2 == 0)
    {
        firsthalf = n / divider;
    }
    else
    {
        firsthalf = n / (divider*10);
    }
    while (firsthalf > 0)
    {
        reversedFirsthalf = reversedFirsthalf * 10 + firsthalf%10;
        firsthalf = firsthalf / 10;
    }
    for (int i = 0;i < length / 2;i++)
    {
        if (reversedFirsthalf % 10 != secondhalf % 10)
        {
            return false;
        }
        else
        {
            reversedFirsthalf /= 10;
            secondhalf /= 10;
        }
    }
    return true;
}
int main()
{
    int n = 0;
    cin >> n;
    cout<<isPalindrome(n);
}
