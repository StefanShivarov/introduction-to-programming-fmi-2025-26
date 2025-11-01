#include <iostream>
using namespace std;

bool askUser(const int from, const int to) {
    int a;
    cin >> a;
    if (a >= from && a <= to) { cout << a; return true; }
    else { return false; }
    }
int main()
{
    int x, y;
    cin >> x >> y;
    while (askUser(x, y) != true)
    {
        ;
    }
}
