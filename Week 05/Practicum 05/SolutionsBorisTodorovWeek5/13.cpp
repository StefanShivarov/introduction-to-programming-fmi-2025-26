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
int simplify(int& a, int& b,int(*f)(int,int))
{
    int nodVar = nod(a, b);
    a /= nodVar;
    b /= nodVar;
    return f(a,b);
}
int main()
{
    int a = 16, b = 20;
    int result = simplify(a, b, [](int x, int y) { return x * y; });
    cout << a << ' ' << b << ' ' << result;
}
