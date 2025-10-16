#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int n;
    char c;
    cin >> n>>c;
    int stars = 1;
    int spaces = n - 1;
    for (int j = 0;j < n;j++)
    {
        for (int i = 0;i < spaces;i++)
        {
            cout << ' ';
        }
        for (int i = 0;i < stars;i++)
        {
            cout << c;
        }
        stars += 2;
        spaces -= 1;
        cout << endl;
    }
    spaces += 1;
    stars -= 2;
    for (int j = 0;j < n-1;j++)
    {
        spaces += 1;
        stars -= 2;
        for (int i = 0;i < spaces;i++)
        {
            cout << ' ';
        }
        for (int i = 0;i < stars;i++)
        {
            cout << c;
        }
        cout << endl;
    }
}
