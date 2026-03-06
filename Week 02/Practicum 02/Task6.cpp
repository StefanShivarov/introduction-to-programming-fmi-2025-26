#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum = sum * 10 + k * i;
    cout << sum << endl;
}