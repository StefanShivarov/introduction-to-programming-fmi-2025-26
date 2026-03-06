#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    int n1 = 0;
    int n2 = n;
    while (n > 0) {
        n1 = n * 10 + n % 10;
        n /= 10;
    }
    return n1 == n2;
}
int main() {
    int n;
    cin >> n;
    if (isPalindrome(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}