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
int sortDigits(unsigned int a)
{
    int aTemp = a;
    int sortedNum = 0;
    int digit = 9;
    int length = getLength(a);
    int multiplierToAdd = 1;
    int multiplierToRemove = 1;
    for (int i = 0;i < length-1;i++)
    {
        multiplierToAdd *= 10;
    }

    for (int i = 0;i < length;i++)
    {
        for (int j = 0;j < length;j++)            
        {
            if (aTemp % 10 < digit )
            {
                if (aTemp % 10 != 0)
                {
                    digit = aTemp % 10;
                    multiplierToRemove = 1;
                    for (int k = 0;k < j;k++)
                    {
                        multiplierToRemove *= 10;
                    }
                }
            }
            aTemp /= 10;
        }
        a = a - digit * multiplierToRemove;
        sortedNum = sortedNum + digit * multiplierToAdd;
        multiplierToAdd /= 10;
        multiplierToRemove = 1;
        aTemp = a;
        digit = 9;
    }
    return sortedNum;
}
int main()
{
    int a = 0;
    cin >> a;
    cout << sortDigits(a);
}
