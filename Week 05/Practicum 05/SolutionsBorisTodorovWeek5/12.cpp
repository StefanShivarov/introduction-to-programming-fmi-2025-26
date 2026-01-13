#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int nod(int a, int b)
{
    for (int i = a;i > 0;i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
}
int simplifyAndSum(int& a, int& b)
{
    int nodVar = nod(a, b);
    a /= nodVar;
    b /= nodVar;
    return a + b;
}
int main()
{
    int a = 16, b = 20;
    int result = simplifyAndSum(a, b);
    cout << a << ' ' << b << ' ' << result;
}
