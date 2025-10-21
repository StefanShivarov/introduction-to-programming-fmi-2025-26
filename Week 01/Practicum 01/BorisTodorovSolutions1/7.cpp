#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int r;
    int x;
    int y;
    cin >> r;
    cin >> x;
    cin >> y;
    if (r > x && r > y)
    {
        cout << "inside";
    }
    else if (r == x || r == y)
    {
        cout << "on the circle";
    }
    else
    {
        cout << "outside";
    }
}
