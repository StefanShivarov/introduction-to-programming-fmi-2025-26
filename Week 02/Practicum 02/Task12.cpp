#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int counter = n * 5 - 3;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        if (i == n) {
            for (int j = 0; j < n; j++)
                cout << "-";
            cout << " ";
            for (int j = i; j >= 1; j--)
                cout << j << " ";
            cout << endl;
            break;
        }
        for (int j = 0; j < counter; j++)
            cout << " ";
        counter -= n;
        for (int j = i; j >= 1; j--)
            cout << j << " ";
        cout << endl;
    }
    counter += n;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        for (int j = 0; j < counter; j++)
            cout << " ";
        counter += n;
        for (int j = i; j >= 1; j--)
            cout << j << " ";
        cout << endl;
    }
}