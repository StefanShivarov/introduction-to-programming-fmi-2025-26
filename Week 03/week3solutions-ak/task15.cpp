
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        int sum = 0;
        while (num >= 1)
        {
            sum += num % 10;
            num /= 10;
        }
        if (sum % 2 == 0) { cout << i << " "; }
    }
}
