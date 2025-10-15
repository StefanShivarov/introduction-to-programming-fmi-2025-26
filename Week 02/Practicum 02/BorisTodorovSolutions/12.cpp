#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    int numToPrint = 1;
    cin >> n;
    int rows = n * 2 - 1;
    int spaces = n * 3 - 2;

    for (int i = 1;i < n+1;i++)
    {
        numToPrint = 1;
        for (int j = 0;j < i;j++)
        {
            cout << numToPrint;
            numToPrint++;
        }
        for (int j = 0;j < spaces;j++)
        {
            if (i == n)
            {
                cout << '-';
            }
            else
            {
                cout << ' ';
            }
        }
        for (int j = 0;j < i;j++)
        {
            numToPrint--;
            cout << numToPrint;
        }
            spaces -= 2;
        cout << endl;
    }
    spaces += 4;
    for (int i = n-1;i >0;i--)
    {
        numToPrint = 1;
        for (int j = 0;j < i;j++)
        {
            cout << numToPrint;
            numToPrint++;
        }
        for (int j = 0;j < spaces;j++)
        {
            cout << ' ';
        }
        for (int j = 0;j < i;j++)
        {
            numToPrint--;
            cout << numToPrint;
        }
        spaces += 2;
        cout << endl;
    }
}
