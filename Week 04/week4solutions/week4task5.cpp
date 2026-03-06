#include <iostream>
using namespace std;

bool palindrome(int n) {
    int number = n;
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return number == reversed;
}

int main()
{
    int x;
    cin >> x;
    if (palindrome(x)) { cout << "true"; }
    else { cout << "false"; }
}