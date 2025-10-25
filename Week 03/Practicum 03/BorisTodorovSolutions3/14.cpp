#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n = 0;
    int count = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    cout << count;
}
