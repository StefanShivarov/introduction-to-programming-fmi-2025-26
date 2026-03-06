#include <iostream>
using namespace std;

bool isPrime(int num) {
    int counter = 0;
    if (num <= 1)
        return false;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}
void decomposition(int n) {
    bool first = true;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i) && n % i == 0) {
            if (!first)
                cout << ".";
            cout << i;
            n /= i;
            i--;
            first = false;
        }
    }
}
int main() {
    int num;
    cin >> num;
    decomposition(num);
}