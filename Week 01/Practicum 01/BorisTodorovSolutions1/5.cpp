#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int a;
    int x1;
    int x2;
    int x3;
    int x4;
    double avr;
    double sum;
    cin >> a;
    x4 = a % 10;
    x3 = (a % 100)/10;
    x2 = (a % 1000)/100;
    x1 = (a % 10000)/1000;
    sum = x1 + x2 + x3 + x4;
    avr = sum / 4;
    cout << "sum:";cout << sum<< endl;
    cout << "p:";cout << x1 * x2 * x3 * x4 << endl;
    cout << "avg:";cout << avr << endl;
}
