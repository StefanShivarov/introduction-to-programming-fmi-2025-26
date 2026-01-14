#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (i % 10 == 6 || i % 10 == 8)
            sum += i;
    cout << sum;
}