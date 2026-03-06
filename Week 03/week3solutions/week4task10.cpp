#include <iostream>
using namespace std;

int sortDigits(int n) {
    int count[10] = {0};
    while (n > 0) 
    {
        int digit = n % 10;  
        count[digit]++;  
        n /= 10;  
    }
    int result = 0;
    for (int i = 0; i <= 9; i++) 
    {
        while (count[i] > 0) 
        {
            result = result * 10 + i;
            count[i]--;
        }
    }
    return result;
}

int main() 
{
    int n;
    cin >> n;
    cout << sortDigits(n);
}