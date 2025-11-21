#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    char b[n];
    for (int i = 0; i < n; i++)
        b[i] = a[n - i - 1];
    bool sym = true;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) {
            sym = false;
            break;
        }
    if (sym)
        cout << "Yes, the array is symmetric.";
    else
        cout << "No, the array is not symmetric.";
}