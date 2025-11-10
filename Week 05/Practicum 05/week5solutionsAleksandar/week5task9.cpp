#include <iostream>
#include <cmath>
using namespace std;

void lcm(int a, int b) {
    for (int i = 1; ; i++)
    {
        if (i % a == 0 && i % b == 0) { cout << i; break; }
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    lcm(a, b);
}