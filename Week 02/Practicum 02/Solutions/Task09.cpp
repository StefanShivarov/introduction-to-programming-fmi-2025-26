#include <iostream>

using namespace std;

int main() {
    int n;
    char s;

    cin >> n >> s;

    int symbol_count = 1;

    for (int row = 0; row < n * 2 - 1; row++) {
        for (int space = 0; space < n - symbol_count / 2 - 1; space++) {
            cout << ' ';
        }

        for (int symbol = 0; symbol < symbol_count; symbol++) {
            cout << s;
        }

        if (row < n - 1) {
            symbol_count += 2;
        } else {
            symbol_count -= 2;
        }

        cout << endl;
    }

    return 0;
}
