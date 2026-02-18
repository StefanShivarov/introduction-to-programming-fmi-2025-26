#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (j <= i)
                cout << j << " ";
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j < n; j++)
            if (j <= i)
                cout << j << " ";
        cout << endl;
    }
}