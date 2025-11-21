#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % 2 != 0) {
                cout << i + n * j << " ";
            }
            else {
                cout << i * (i - n) * j << " ";
            }
        }
        cout << endl;
    }
}
