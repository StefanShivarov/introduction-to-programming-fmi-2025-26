#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n = 0;
    int num = 1;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        for (int j = 1;j < n+1;j++)
        {
            if (j < num)
            {
                cout << '*';
            }
            else if (j == num)
            {
                cout << num;
            }
            else
            {
                cout << '.';
            }
        }
        cout << endl;
        num++;
    }
}
