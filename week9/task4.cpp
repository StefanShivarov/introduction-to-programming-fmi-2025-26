#include <iostream>
using namespace std;
const int MAX = 50;
void fromDecimalToKthBase(char num[MAX], const int k, unsigned number, int& counter) {
    while (number) {
        if (number % k < 10)
            num[counter++] = number % k + '0';
        else
            num[counter++] = number % k + 'A' - 10;
        number /= k;
    }
}
bool isPalindrome(const char num[MAX], const int n) {
    for (int i = 0; i < n / 2; i++)
        if (num[i] != num[n - 1 - i])
            return false;
    return true;
}
int main() {
    unsigned n = 0;
    int k;
    cout << "Number in decimal: ";
    cin >> n;
    cout << "Numeral system: ";
    cin >> k;
    char num[MAX];
    int counter = 0;
    fromDecimalToKthBase(num, k, n, counter);
    if (isPalindrome(num, counter))
        cout << "true";
    else
        cout << "false";
}