#include <iostream>

using std::cin;
using std::cout;

unsigned reversed(unsigned number) {
    unsigned result = 0;
    while (number) {
        result *= 10;
        result += number % 10;
        number /= 10;
    }
    return result;
}

bool isPalindrome(unsigned number) {
    return number == reversed(number);
}

int main() {
    int num;
    cin >> num;

    cout << isPalindrome(num);
}
