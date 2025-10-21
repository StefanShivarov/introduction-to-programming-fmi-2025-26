#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n = 0;
    int sumOfNums = 0;
    int num = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        sumOfNums = 0;
        num = i;
        while (num >= 1)
        {
            sumOfNums += num % 10;
            num = num/10;
        }
        if (sumOfNums % 2 == 0)
        {
            cout << i<<" ";
        }
    }
}
