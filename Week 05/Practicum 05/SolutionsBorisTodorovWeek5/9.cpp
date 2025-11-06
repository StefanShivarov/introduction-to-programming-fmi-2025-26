#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int lcm(int first, int second)
{
    int i = 1;
    while (true)
    {
        if (i % first == 0 && i % second == 0)
        {
            return i;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int a;
        int b;
    cin >> a >> b;
    cout << lcm(a, b);
}