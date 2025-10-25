#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    double a;
    double b;
    cin >> a;
    cin >> b;
    a += b;
    b = a - b;
    a = a - b;
    cout << "a:";cout << a << endl;
    cout << "b:";cout << b;
}
