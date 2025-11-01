#include <iostream>
using namespace std;

bool palindrome(int n){
    int number = n;
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    if (number == reversed) { return true; }
    else { return false; }
}
int main()
{
    int x;
    cin >> x;
    bool result = false;
    cout << result;
}
