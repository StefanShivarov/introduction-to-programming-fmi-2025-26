#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    unsigned n;
    cin >> n;

    int currentNum = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << currentNum++ << ' ';
        }
        cout << endl;
    }
}
