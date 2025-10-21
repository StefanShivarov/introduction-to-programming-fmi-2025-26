#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cin >> n;

    int current;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                current = j * n + i + 1;
            } else {
                current = (j + 1) * n - i;
            }
            cout << current;
            if (j != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

}