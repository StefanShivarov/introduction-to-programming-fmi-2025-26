#include <iostream>
using namespace std;
int singleDigitSum(int n) 
{
    while (n >= 10)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }
    return n;
}   
int main() 
{
    int n;
    cin >> n;
    cout << singleDigitSum(n) << endl;
}