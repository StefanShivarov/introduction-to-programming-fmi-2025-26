#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        cout << s;
        for (int j = 0; j < i * 2; j++)
            cout << s;
        cout << endl;
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        cout << s;
        for (int j = 0; j < i * 2; j++)
            cout << s;
        cout << endl;
    }
}