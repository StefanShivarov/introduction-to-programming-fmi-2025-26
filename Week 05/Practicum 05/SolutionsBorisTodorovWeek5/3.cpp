#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void sort3(int& min, int& mid, int& max)
{
    int temp = 0;
    if (min > mid)
    {
        temp = min;
        min = mid;
        mid = temp;
    }
    if (min > max)
    {
        temp = min;
        min = max;
        max = temp;
    }
    if (mid > max)
    {
        temp = mid;
        mid = max;
        max = temp;
    }
}
int main()
{
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    sort3(a, b, c);
    cout << a <<" " << b <<" " << c;
}
