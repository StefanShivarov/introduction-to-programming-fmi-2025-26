#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    unsigned n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) {
                cout << 0 << ' ';
                continue;
            }
            cout << 1 << ' ';
        }
        cout << endl;
    }
}
