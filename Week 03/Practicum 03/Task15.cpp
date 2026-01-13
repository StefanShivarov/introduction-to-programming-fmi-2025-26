#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        int k = i;
        while (k > 0) {
            sum += k % 10;
            k /= 10;
        }
        if (sum % 2 == 0)
            cout << i << " ";
    }
}