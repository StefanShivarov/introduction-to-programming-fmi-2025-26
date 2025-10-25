#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n = 0;
    int num = 1;
    cin >> n;
    for (int i = 1;i < n+1;i++)
    {
        for (int j = 0;j < i;j++)
        {
            cout << num++ <<" ";
        }
        cout << endl;
    }

}
