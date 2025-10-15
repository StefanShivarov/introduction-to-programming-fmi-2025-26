#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    int rows;
    int finalNum;
    int currentNum=1;
    cin >> n;
    rows = n;
    finalNum = n * n;
    for (int j = 0;j < rows;j++)
    {
        for (int i = 0;i < rows;i++)
        {
            if (i % 2 == 0)
            {
                cout << currentNum<<" ";
                currentNum += 2 * rows - 1-2*j;
            }
            else
            {
                cout << currentNum<<" ";
                currentNum += 1+2*j;
            }

        }
        cout << endl;
        currentNum = j + 2;
    }
}