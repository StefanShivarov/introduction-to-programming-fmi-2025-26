#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int getDivision(int first, int second)
{
    int result = 0;
    while (first >= second)
    {
        first -= second;
        result++;
    }
    return result;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << getDivision(a, b);
}
