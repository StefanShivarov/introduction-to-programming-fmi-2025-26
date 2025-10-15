#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int n;
    int sum = 0;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum;
}