#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cin >> n;

    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 10 == 6 || i % 10 == 8) {
            result += i;
        }
    }

    cout << result;
}
