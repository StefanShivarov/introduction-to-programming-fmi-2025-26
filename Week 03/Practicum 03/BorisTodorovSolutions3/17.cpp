#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n = 0;
    cin >> n;
    for (int rows = 0;rows < n;rows++)
    {
        for (int collumns = 0;collumns < n;collumns++)
        {
            if (collumns > rows)
            {
                cout << 0<<" ";
            }
            else
            {
                cout << 1<<" ";
            }
        }
        cout << endl;
    }
}
