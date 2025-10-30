#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int sumOfDigits(long long n)
{
    int sum=0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    long long n = 0;
    cin >> n;
    while (n >= 10)
    {
        n = sumOfDigits(n);
        cout << n<<endl;
    }
}
