

#include <iostream>
using namespace std;
int main()
{
    int i;
    cin >> i;
    int num = 1;
    for (int j = 0; j < i; j++)
    {
        for (int k = 0; k <= j; k++)
        {
            cout << num++ << " ";
        }
        cout << endl;
    }
}