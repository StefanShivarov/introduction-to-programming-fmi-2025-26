#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n + 1;i++)
    {
        for (int j=i;j < n;j++)
        {
            cout << ' ';
        }
        for (int j = 0;j < i;j++)
        {
            cout << '*';
        }
        cout << '|';
        for (int j = 0;j < i;j++)
        {
            cout << '*';
        }
        for (int j = i;j < n;j++)
        {
            cout << ' ';
        }
        cout << endl;
    }
}