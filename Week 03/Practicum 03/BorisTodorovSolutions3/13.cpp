#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n = 0;
    int sum = 0;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        if (i % 10 == 6 || i % 10 == 8)
        {
            sum += i;
        }
    }
    cout << sum;
}
