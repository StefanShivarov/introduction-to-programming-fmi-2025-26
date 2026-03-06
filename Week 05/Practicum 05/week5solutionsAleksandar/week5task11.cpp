#include <iostream>
#include <cmath>
using namespace std;

bool isSquareRoot(int number) {
    bool result = false;
    for (int i = 1; i <= number; i++)
    {
        if (i * i == number) { result = true; }
    }
    return result;
}
int main()
{
    int a;
    cin >> a;
    cout << boolalpha << isSquareRoot(a);
}